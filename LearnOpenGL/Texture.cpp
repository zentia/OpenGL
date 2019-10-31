#include "Texture.h"
#include <DbgHelp.h>

const char* Texture::rootDir = "Assets/Texture/";

std::string TrackStack()
{
	static const int MAX_STACK_FRAMES = 5;
	void* pStack[MAX_STACK_FRAMES];

	HANDLE process = GetCurrentProcess();
	SymInitialize(process, NULL, TRUE);
	WORD frames = CaptureStackBackTrace(0, MAX_STACK_FRAMES, pStack, NULL);

	std::ostringstream oss;
	oss << "stack traceback: " << std::endl;
	for (WORD i = 0; i < frames; ++i)
	{
		DWORD64 address = (DWORD64)(pStack[i]);

		DWORD64 displacementSym = 0;
		char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
		PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;
		pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		pSymbol->MaxNameLen = MAX_SYM_NAME;

		DWORD displacementLine = 0;
		IMAGEHLP_LINE64 line;
		line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

		if (SymFromAddr(process, address, &displacementSym, pSymbol) && SymGetLineFromAddr64(process, address, &displacementLine, &line))
		{
			oss << "\t" << pSymbol->Name << " at " << line.FileName << ":" << line.LineNumber << "(0x" << std::hex << pSymbol->Address << std::dec << ")" << std::endl;
		}
		else
		{
			oss << "\terror: " << GetLastError() << std::endl;
		}
	}
	return oss.str();
}

Texture::Texture(const std::string path, int format, int index)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, nrChannels;
	std::string szPath = rootDir + path;
	unsigned char* data = stbi_load(szPath.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture " << szPath << std::endl << TrackStack() << std::endl;
		
	}
	stbi_image_free(data);
	activeIndex = index;
}

void Texture::Update()
{
	glActiveTexture(activeIndex);
	glBindTexture(GL_TEXTURE_2D, ID);
}