/**
 * File:   slider_circle.h
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

#ifndef TK_SLIDER_CIRCLE_H
#define TK_SLIDER_CIRCLE_H

#include "base/widget.h"

BEGIN_C_DECLS
/**
 * @class slider_circle_t
 * @parent widget_t
 * @annotation ["scriptable","design","widget"]
 * 环形slider。
 * 在xml中使用"slider\_circle"标签创建控件。如：
 *
 * ```xml
 * <!-- ui -->
 * <slider_circle start_angle="120" end_angle="420" line_cap="round" value="30" counter_clock_wise="true" bg_line_width="2" fg_line_width="8"/>
 * ```
 *
 * 可用通过style来设置控件的显示风格，如字体的大小和颜色等等。如：
 * 
 * ```xml
 * <!-- style -->
 * <style name="default" font_size="18" bg_color="black" fg_color="#00f000">
 *   <normal text_color="black" dragger_color="#E00000"/>
 *   <pressed text_color="black" dragger_color="#FF0000"/>
 * </style>
 * ```
 */
typedef struct _slider_circle_t {
  widget_t widget;

  /**
   * @property {double} value
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 值。
   */
  double value;

  /**
   * @property {double} min
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 最小值。
   */
  double min;

  /**
   * @property {double} max
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 最大值。
   */
  double max;

  /**
   * @property {double} step
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 步长。
   */
  double step;

  /**
   * @property {int16_t} start_angle
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 最小值对应的角度。
   */
  int16_t start_angle;

  /**
   * @property {int16_t} end_angle
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 最大值对应的角度。
   */
  int16_t end_angle;

  /**
   * @property {uint8_t} fg_line_width
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 前景线条宽带。
   */
  uint8_t fg_line_width;

  /**
   * @property {uint8_t} bg_line_width
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 背景线条宽带。
   */
  uint8_t bg_line_width;

  /**
   * @property {uint8_t} header_size
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 头部圆圈半径大小(0不显示头部)。
   */
  uint8_t header_size;

  /**
   * @property {uint8_t} dragger_size
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 拖动有效区域半径大小。
   */
  uint8_t dragger_size;

  /**
   * @property {char*} line_cap
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 线帽类型(round:圆头，square:方头，butt:平头)。
   */
  char* line_cap;

  /**
   * @property {bool_t} counter_clock_wise
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否为逆时针方向(缺省为FALSE)。
   */
  bool_t counter_clock_wise;

  /**
   * @property {bool_t} show_text
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否显示文本。
   */
  bool_t show_text;

  /**
   * @property {char*} format
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 文本格式字符串。
   */
  char* format;

  /*private*/
  double save_value;
  double prev_value;
  bool_t dragging;
} slider_circle_t;

/**
 * @method slider_circle_create
 * @annotation ["constructor", "scriptable"]
 * 创建slider_circle对象
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} slider_circle对象。
 */
widget_t* slider_circle_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method slider_circle_cast
 * 转换为slider_circle对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget slider_circle对象。
 *
 * @return {widget_t*} slider_circle对象。
 */
widget_t* slider_circle_cast(widget_t* widget);

/**
 * @method slider_circle_set_value
 * 设置 值。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {double} value 值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_value(widget_t* widget, double value);

/**
 * @method slider_circle_set_min
 * 设置 最小值。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {double} min 最小值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_min(widget_t* widget, double min);

/**
 * @method slider_circle_set_max
 * 设置 最大值。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {double} max 最大值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_max(widget_t* widget, double max);

/**
 * @method slider_circle_set_step
 * 设置 步长。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {double} step 步长。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_step(widget_t* widget, double step);

/**
 * @method slider_circle_set_start_angle
 * 设置 最小值对应的角度。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {int16_t} start_angle 最小值对应的角度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_start_angle(widget_t* widget, int16_t start_angle);

/**
 * @method slider_circle_set_end_angle
 * 设置 最大值对应的角度。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {int16_t} end_angle 最大值对应的角度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_end_angle(widget_t* widget, int16_t end_angle);

/**
 * @method slider_circle_set_fg_line_width
 * 设置 前景线条宽带。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint8_t} fg_line_width 前景线条宽带。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_fg_line_width(widget_t* widget, uint8_t fg_line_width);

/**
 * @method slider_circle_set_bg_line_width
 * 设置 背景线条宽带。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint8_t} bg_line_width 背景线条宽带。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_bg_line_width(widget_t* widget, uint8_t bg_line_width);

/**
 * @method slider_circle_set_header_size
 * 设置 头部圆圈半径大小。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint8_t} header_size 头部圆圈半径大小。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_header_size(widget_t* widget, uint8_t header_size);

/**
 * @method slider_circle_set_dragger_size
 * 设置 拖动有效区域半径大小。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint8_t} dragger_size 拖动有效区域半径大小。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_dragger_size(widget_t* widget, uint8_t dragger_size);

/**
 * @method slider_circle_set_line_cap
 * 设置 线帽类型(round:圆头，square:方头，butt:平头)。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {const char*} line_cap 线帽类型(round:圆头，square:方头，butt:平头)。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_line_cap(widget_t* widget, const char* line_cap);

/**
 * @method slider_circle_set_counter_clock_wise
 * 设置 是否为逆时针方向(缺省为FALSE)。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {bool_t} counter_clock_wise 是否为逆时针方向(缺省为FALSE)。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_counter_clock_wise(widget_t* widget, bool_t counter_clock_wise);

/**
 * @method slider_circle_set_show_text
 * 设置 是否显示文本。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {bool_t} show_text 是否显示文本。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_show_text(widget_t* widget, bool_t show_text);

/**
 * @method slider_circle_set_format
 * 设置 文本格式字符串。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {const char*} format 文本格式字符串。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t slider_circle_set_format(widget_t* widget, const char* format);

#define SLIDER_CIRCLE_PROP_VALUE "value"
#define SLIDER_CIRCLE_PROP_MIN "min"
#define SLIDER_CIRCLE_PROP_MAX "max"
#define SLIDER_CIRCLE_PROP_STEP "step"
#define SLIDER_CIRCLE_PROP_START_ANGLE "start_angle"
#define SLIDER_CIRCLE_PROP_END_ANGLE "end_angle"
#define SLIDER_CIRCLE_PROP_FG_LINE_WIDTH "fg_line_width"
#define SLIDER_CIRCLE_PROP_BG_LINE_WIDTH "bg_line_width"
#define SLIDER_CIRCLE_PROP_HEADER_SIZE "header_size"
#define SLIDER_CIRCLE_PROP_DRAGGER_SIZE "dragger_size"
#define SLIDER_CIRCLE_PROP_LINE_CAP "line_cap"
#define SLIDER_CIRCLE_PROP_COUNTER_CLOCK_WISE "counter_clock_wise"
#define SLIDER_CIRCLE_PROP_SHOW_TEXT "show_text"
#define SLIDER_CIRCLE_PROP_FORMAT "format"

#define WIDGET_TYPE_SLIDER_CIRCLE "slider_circle"

#define SLIDER_CIRCLE(widget) ((slider_circle_t*)(slider_circle_cast(WIDGET(widget))))

/*public for subclass and runtime type check*/
TK_EXTERN_VTABLE(slider_circle);

/*public for test*/
/**
 * @method slider_circle_is_point_in_dragger
 * 判断点是否在拖动区域内。
 * @param {widget_t*} widget widget对象。
 * @param {xy_t} x x坐标。
 * @param {xy_t} y y坐标。
 *
 * @return {bool_t} 返回TRUE表示在拖动区域内，否则表示不在。
 */
bool_t slider_circle_is_point_in_dragger(widget_t* widget, xy_t x, xy_t y);

/**
 * @method slider_circle_point_to_angle
 * 将点转换为角度。
 * @param {widget_t*} widget widget对象。
 * @param {xy_t} x x坐标。
 * @param {xy_t} y y坐标。
 * 
 * @return {double} 返回角度。
 */
double slider_circle_point_to_angle(widget_t* widget, xy_t x, xy_t y);

/**
 * @method slider_circle_angle_to_value
 * 将角度转换为值。
 * @param {widget_t*} widget widget对象。
 * @param {double} angle 角度。
 * 
 * @return {double} 返回值。
 */
double slider_circle_angle_to_value(widget_t* widget, double angle);

/**
 * @method slider_circle_point_to_value
 * 将点转换为值。
 * @param {widget_t*} widget widget对象。
 * @param {xy_t} x x坐标。
 * @param {xy_t} y y坐标。
 * 
 * @return {double} 返回值。
 */
double slider_circle_point_to_value(widget_t* widget, xy_t x, xy_t y);

END_C_DECLS

#endif /*TK_SLIDER_CIRCLE_H*/
