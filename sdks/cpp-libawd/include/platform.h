#ifndef _LIBAWD_AWDW32_H
#define _LIBAWD_AWDW32_H

#ifdef WIN32
#include <io.h>
#include <windows.h>
#include <sys/stat.h>
#include <fcntl.h>

#define open _open
#define lseek _lseek
#define write _write
#define read _read
#define close _close
#define unlink _unlink

#define off_t int

#else // UNIX

#include <unistd.h>

#endif // WIN32

#endif
