#include "Engine.h"

int main()
{
	auto pApp = new CEngine();
	if (pApp != nullptr)	pApp->Initialize();
	if (pApp != nullptr)	pApp->Run();
	if (pApp != nullptr)	pApp->Finalize();

	if (pApp != nullptr) {
		delete pApp;
		pApp = nullptr;
	}
}