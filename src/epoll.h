/**
 */

#include "common/basics.h"
#include "common/log.h"
#include "common/shared_ptr.h"
#include "src/multiplexer.h"

#include <sys/epoll.h>

class Epoll : public Multiplexer {
 public:
  Epoll() {}
  virtual ~Epoll() {}
  virtual int AddEvent(shared_ptr<Event> e);
  virtual int DelEvent(shared_ptr<Event> e);
  virtual void ProcessEvents();

 private:
  void Init();

  int epoll_fd_;

  DO_NOT_COPY_AND_ASSIGN(Epoll);
};
