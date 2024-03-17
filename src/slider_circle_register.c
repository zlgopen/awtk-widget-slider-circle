/**
 * File:   slider_circle.c
 * Author: AWTK Develop Team
 * Brief:  环形slider。
 *
 * Copyright (c) 2024 - 2024 Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2024-03-13 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "slider_circle_register.h"
#include "base/widget_factory.h"
#include "slider_circle/slider_circle.h"

ret_t slider_circle_register(void) {
  return widget_factory_register(widget_factory(), WIDGET_TYPE_SLIDER_CIRCLE, slider_circle_create);
}

const char* slider_circle_supported_render_mode(void) {
  return "OpenGL|AGGE-BGR565|AGGE-BGRA8888|AGGE-MONO";
}
