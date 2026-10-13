// implementstion file for Connection::Connection

#include "Connection.h"

#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>

inline int Connection::Socket::safeRead(int fd, void* buf, std::size_t count) {
  int retval;
  retval = read(fd, buf, count);
  if (retval == -1) {
    throw NetworkError{
        std::format("read {} bytes from fd {} FAILED", count, fd)};
  }
  return retval;
}

inline int Connection::Socket::safeWrite(int fd, const char* buf,
                                         std::size_t count) {
  int retval;
  retval = write(fd, buf, count);
  if (retval == -1) {
    throw NetworkError{
        std::format("write {} bytes to fd {} FAILED", count, fd)};
  }
  return retval;
}
