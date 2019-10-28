#pragma once
#include "Object.h"

#include <tchar.h>
#include <iomanip>

class FileWatcher : public Object
{
public:
	FileWatcher();
	~FileWatcher();
	void Update();
	static FileWatcher* instance;
	static void ListenFile(const std::string& path);
	static void Start();
	void Execute();
	HANDLE dirHandle;
	char notify[1024];
	FILE_NOTIFY_INFORMATION* pNotify;
	DWORD cbBytes;
	WCHAR fileName[MAX_PATH];
	char fileRename[MAX_PATH];
};

