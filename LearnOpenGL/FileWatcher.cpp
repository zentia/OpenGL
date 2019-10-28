#include "FileWatcher.h"
#include "Event.h"
#include <thread>

FileWatcher* FileWatcher::instance = NULL;

FileWatcher::FileWatcher()
{

	dirHandle = CreateFile(_T("Assets"), FILE_LIST_DIRECTORY, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS|FILE_FLAG_OVERLAPPED, NULL);
	if (dirHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "error" << GetLastError() << std::endl;
	}
	memset(notify, 0, strlen(notify));
	pNotify = (FILE_NOTIFY_INFORMATION*)notify;
	instance = this;
	std::thread t(Start);
	t.detach();// 后台允许，无需等待线程完成
}

FileWatcher::~FileWatcher()
{
	CloseHandle(dirHandle);
}

void FileWatcher::Update()
{
	
}

void FileWatcher::ListenFile(const std::string& path)
{

}

void FileWatcher::Start()
{
	instance->Execute();
}



bool IsDirectory(const LPTSTR& strPath)
{
	DWORD dwAttrib = GetFileAttributes(strPath);
	return static_cast<bool>((dwAttrib != 0xffffffff && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY)));
}

void FileWatcher::Execute()
{
	const WCHAR* lpPath = _T("Assets\\");
	bool dirty = false;
	while (true)
	{
		if (ReadDirectoryChangesW(dirHandle, &notify, 1024, true, FILE_NOTIFY_CHANGE_LAST_WRITE, &cbBytes, NULL, NULL))
		{
			memset(fileName, 0, MAX_PATH);
			memcpy(fileName, lpPath, _tcslen(lpPath) * sizeof(WCHAR));
			memcpy(fileName + _tcslen(lpPath), pNotify->FileName, pNotify->FileNameLength);
			if (pNotify->FileName)
			{
				int num = WideCharToMultiByte(CP_OEMCP, NULL, fileName, -1, NULL, 0, NULL, FALSE);
				char* pchar = new char[num];
				WideCharToMultiByte(CP_OEMCP, NULL, fileName, -1, pchar, num, NULL, FALSE);
				if (dirty)
				{
					if (!IsDirectory(fileName))
					{
						printf("[%s][%d]\n", pchar, pNotify->Action);
					}
				}
				dirty = !dirty;
			}
			if (pNotify->NextEntryOffset != 0 && (pNotify->FileNameLength > 0 && pNotify->FileNameLength < MAX_PATH))
			{
				PFILE_NOTIFY_INFORMATION p = (PFILE_NOTIFY_INFORMATION)((char*)pNotify + pNotify->NextEntryOffset);
				memset(fileRename, 0, sizeof(fileRename));
				WideCharToMultiByte(CP_ACP, 0, p->FileName, p->FileNameLength / 2, fileRename, 99, NULL, NULL);
			}
			
			switch (pNotify->Action)
			{
			case FILE_ACTION_ADDED:
				break;
			case FILE_ACTION_MODIFIED:
				
				Event::Dispatch(Event::Type::FileModify, fileName);
				break;
			case FILE_ACTION_REMOVED:
				break;
			case FILE_ACTION_RENAMED_OLD_NAME:
				break;
			}
		}
	}
}