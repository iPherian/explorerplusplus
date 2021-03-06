#pragma once

#include <windows.h>


typedef void (*OnDirectoryAltered)(TCHAR *szFileName, DWORD dwAction, void *pData);

/* Main exported interface. */
__interface IDirectoryMonitor : IUnknown
{
	int WatchDirectory(const TCHAR *Directory, UINT WatchFlags,
		OnDirectoryAltered onDirectoryAltered, BOOL bWatchSubTree,
		void *pData);
	int WatchDirectory(HANDLE hDirectory, const TCHAR *Directory,
		UINT WatchFlags, OnDirectoryAltered onDirectoryAltered,
		BOOL bWatchSubTree, void *pData);
	BOOL StopDirectoryMonitor(int iStopIndex);
};

HRESULT CreateDirectoryMonitor(IDirectoryMonitor **pDirectoryMonitor);