#include "awtk.h"
#include "slider_circle_register.h"

static ret_t on_close(void* ctx, event_t* e) {
  tk_quit();

  return RET_OK;
}

/**
 * 初始化
 */
ret_t application_init(void) {
  slider_circle_register();

  window_open("main");

  return RET_OK;
}

/**
 * 退出
 */
ret_t application_exit(void) {
  log_debug("application_exit\n");
  return RET_OK;
}
