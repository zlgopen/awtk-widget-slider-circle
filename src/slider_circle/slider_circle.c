/**
 * File:   slider_circle.c
 * Author: AWTK Develop Team
 * Brief:  环形slider_circle。
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
#include "slider_circle.h"

static ret_t slider_circle_set_value_internal(widget_t* widget, double value, uint32_t etype,
                                              bool_t force);

static ret_t slider_circle_set_value_internal(widget_t* widget, double value, uint32_t etype,
                                              bool_t force) {
  double step = 0;
  double offset = 0;
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  step = slider_circle->step;
  value = tk_clamp(value, slider_circle->min, slider_circle->max);

  if (step > 0) {
    offset = value - slider_circle->min;
    offset = tk_roundi(offset / step) * step;
    value = slider_circle->min + offset;
  }

  if (slider_circle->value != value || force) {
    value_change_event_t evt;
    value_change_event_init(&evt, etype, widget);
    value_set_double(&(evt.old_value), slider_circle->value);
    value_set_double(&(evt.new_value), value);
    slider_circle->value = value;
    widget_dispatch(widget, (event_t*)&evt);
    widget_invalidate(widget, NULL);
  }

  return RET_OK;
}

ret_t slider_circle_set_value(widget_t* widget, double value) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  if (slider_circle->dragging) {
    return RET_BUSY;
  }

  if (slider_circle->value != value) {
    value_change_event_t evt;
    value_change_event_init(&evt, EVT_VALUE_WILL_CHANGE, widget);
    value_set_double(&(evt.old_value), slider_circle->value);
    value_set_double(&(evt.new_value), value);
    if (widget_dispatch(widget, (event_t*)&evt) == RET_STOP) {
      return RET_OK;
    }

    return slider_circle_set_value_internal(widget, value, EVT_VALUE_CHANGED, FALSE);
  }

  return RET_OK;
}

ret_t slider_circle_set_min(widget_t* widget, double min) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->min = min;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_max(widget_t* widget, double max) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->max = max;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_step(widget_t* widget, double step) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->step = step;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_start_angle(widget_t* widget, int16_t start_angle) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->start_angle = start_angle;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_end_angle(widget_t* widget, int16_t end_angle) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->end_angle = end_angle;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_fg_line_width(widget_t* widget, uint8_t fg_line_width) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->fg_line_width = fg_line_width;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_bg_line_width(widget_t* widget, uint8_t bg_line_width) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->bg_line_width = bg_line_width;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_header_size(widget_t* widget, uint8_t header_size) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->header_size = header_size;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_dragger_size(widget_t* widget, uint8_t dragger_size) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->dragger_size = dragger_size;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_line_cap(widget_t* widget, const char* line_cap) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->line_cap = tk_str_copy(slider_circle->line_cap, line_cap);

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_counter_clock_wise(widget_t* widget, bool_t counter_clock_wise) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->counter_clock_wise = counter_clock_wise;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_show_text(widget_t* widget, bool_t show_text) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->show_text = show_text;

  return widget_invalidate(widget, NULL);
}

ret_t slider_circle_set_format(widget_t* widget, const char* format) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  slider_circle->format = tk_str_copy(slider_circle->format, format);

  return widget_invalidate(widget, NULL);
}

static ret_t slider_circle_get_prop(widget_t* widget, const char* name, value_t* v) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(SLIDER_CIRCLE_PROP_VALUE, name)) {
    value_set_double(v, slider_circle->value);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_MIN, name)) {
    value_set_double(v, slider_circle->min);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_MAX, name)) {
    value_set_double(v, slider_circle->max);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_STEP, name)) {
    value_set_double(v, slider_circle->step);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_START_ANGLE, name)) {
    value_set_int16(v, slider_circle->start_angle);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_END_ANGLE, name)) {
    value_set_int16(v, slider_circle->end_angle);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_FG_LINE_WIDTH, name)) {
    value_set_uint8(v, slider_circle->fg_line_width);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_BG_LINE_WIDTH, name)) {
    value_set_uint8(v, slider_circle->bg_line_width);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_HEADER_SIZE, name)) {
    value_set_uint8(v, slider_circle->header_size);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_DRAGGER_SIZE, name)) {
    value_set_uint8(v, slider_circle->dragger_size);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_LINE_CAP, name)) {
    value_set_str(v, slider_circle->line_cap);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_COUNTER_CLOCK_WISE, name)) {
    value_set_bool(v, slider_circle->counter_clock_wise);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_SHOW_TEXT, name)) {
    value_set_bool(v, slider_circle->show_text);
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_FORMAT, name)) {
    value_set_str(v, slider_circle->format);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t slider_circle_set_prop(widget_t* widget, const char* name, const value_t* v) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(SLIDER_CIRCLE_PROP_VALUE, name)) {
    slider_circle_set_value(widget, value_double(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_MIN, name)) {
    slider_circle_set_min(widget, value_double(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_MAX, name)) {
    slider_circle_set_max(widget, value_double(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_STEP, name)) {
    slider_circle_set_step(widget, value_double(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_START_ANGLE, name)) {
    slider_circle_set_start_angle(widget, value_uint16(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_END_ANGLE, name)) {
    slider_circle_set_end_angle(widget, value_uint16(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_FG_LINE_WIDTH, name)) {
    slider_circle_set_fg_line_width(widget, value_uint8(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_BG_LINE_WIDTH, name)) {
    slider_circle_set_bg_line_width(widget, value_uint8(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_HEADER_SIZE, name)) {
    slider_circle_set_header_size(widget, value_uint8(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_DRAGGER_SIZE, name)) {
    slider_circle_set_dragger_size(widget, value_uint8(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_LINE_CAP, name)) {
    slider_circle_set_line_cap(widget, value_str(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_COUNTER_CLOCK_WISE, name)) {
    slider_circle_set_counter_clock_wise(widget, value_bool(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_SHOW_TEXT, name)) {
    slider_circle_set_show_text(widget, value_bool(v));
    return RET_OK;
  } else if (tk_str_eq(SLIDER_CIRCLE_PROP_FORMAT, name)) {
    slider_circle_set_format(widget, value_str(v));
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t slider_circle_on_destroy(widget_t* widget) {
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(widget != NULL && slider_circle != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(slider_circle->line_cap);
  TKMEM_FREE(slider_circle->format);

  return RET_OK;
}

bool_t slider_circle_is_point_in_dragger(widget_t* widget, xy_t x, xy_t y) {
  double r = 0;
  double cx = 0;
  double cy = 0;
  double value_angle = 0;
  point_t point = {x, y};
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, RET_BAD_PARAMS);

  cx = widget->w / 2;
  cy = widget->h / 2;
  r = tk_min(cx, cy) - slider_circle->fg_line_width / 2;
  r = r - (slider_circle->bg_line_width - slider_circle->fg_line_width) / 2;
  value_angle = tk_value_to_angle(slider_circle->value, slider_circle->min, slider_circle->max,
                                  slider_circle->start_angle, slider_circle->end_angle,
                                  slider_circle->counter_clock_wise);

  point.x = cx + r * cos(value_angle);
  point.y = cy + r * sin(value_angle);

  widget_to_global(widget, &point);

  return tk_distance(point.x, point.y, x, y) < slider_circle->dragger_size;
}

double slider_circle_point_to_angle(widget_t* widget, xy_t x, xy_t y) {
  double angle = 0;
  point_t center = {0, 0};
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, 0);

  center.x = widget->w / 2;
  center.y = widget->h / 2;
  widget_to_global(widget, &center);

  angle = tk_angle(center.x, center.y, x, y);
  /*tk_angle计算的角度是逆时针方向的，这里需要顺时针*/
  angle = 360 - TK_R2D(angle);
  if (angle < slider_circle->start_angle) {
    angle = 360 + angle;
  }

  return angle;
}

#define TK_MUCH_LESS_THAN(a, b) (((a) * 5) < (b))

double slider_circle_angle_to_value(widget_t* widget, double angle) {
  double value = 0;
  double range = 0;
  double range_angle = 0;
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, 0);

  range = slider_circle->max - slider_circle->min;
  range_angle = slider_circle->end_angle - slider_circle->start_angle;

  if (slider_circle->counter_clock_wise) {
    value = slider_circle->min + (range / range_angle) * (slider_circle->end_angle - angle);
  } else {
    value = slider_circle->min + (range / range_angle) * (angle - slider_circle->start_angle);
  }

  {
    double dmin_prev_value = tk_abs(slider_circle->prev_value - slider_circle->min);
    double dmax_prev_value = tk_abs(slider_circle->max - slider_circle->prev_value);
    double dmin_value = tk_abs(value - slider_circle->min);
    double dmax_value = tk_abs(slider_circle->max - value);

    if (TK_MUCH_LESS_THAN(dmin_prev_value, dmax_prev_value)) {
      if (TK_MUCH_LESS_THAN(dmax_value, dmin_value)) {
        /*如果前一个值更靠近最小值，而当前值更靠近最大值，说明在减少的过程中越界了，限制为最小值*/
        value = slider_circle->min;
      }
    }

    if (TK_MUCH_LESS_THAN(dmax_prev_value, dmin_prev_value)) {
      if (TK_MUCH_LESS_THAN(dmin_value, dmax_value)) {
        /*如果前一个值更靠近最大值，而当前值更靠近最小值，说明在增加的过程中越界了，限制为最大值*/
        value = slider_circle->max;
      }
    }
  }

  log_debug("prev=%lf value=%lf\n", slider_circle->prev_value, value);

  return tk_clamp(value, slider_circle->min, slider_circle->max);
}

double slider_circle_point_to_value(widget_t* widget, xy_t x, xy_t y) {
  double angle = 0;
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, 0);

  angle = slider_circle_point_to_angle(widget, x, y);
  return slider_circle_angle_to_value(widget, angle);
}

static ret_t slider_circle_on_paint_self(widget_t* widget, canvas_t* c) {
  double r = 0;
  double cx = 0;
  double cy = 0;
  double value_angle = 0;
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL && c != NULL, RET_BAD_PARAMS);

  cx = widget->w / 2;
  cy = widget->h / 2;
  r = tk_min(cx, cy) - slider_circle->fg_line_width / 2;
  r = r - (slider_circle->bg_line_width - slider_circle->fg_line_width) / 2;
  value_angle = tk_value_to_angle(slider_circle->value, slider_circle->min, slider_circle->max,
                                  slider_circle->start_angle, slider_circle->end_angle,
                                  slider_circle->counter_clock_wise);

  if (slider_circle->counter_clock_wise) {
    widget_draw_arc_at_center(widget, c, FALSE, slider_circle->fg_line_width, value_angle,
                              TK_D2R(slider_circle->end_angle), FALSE, slider_circle->line_cap, r);
  } else {
    widget_draw_arc_at_center(widget, c, FALSE, slider_circle->fg_line_width,
                              TK_D2R(slider_circle->start_angle), value_angle, FALSE,
                              slider_circle->line_cap, r);
  }

  if (slider_circle->header_size > 0) {
    double dragger_x = c->ox + cx + r * cos(value_angle);
    double dragger_y = c->oy + cy + r * sin(value_angle);
    vgcanvas_t* vg = canvas_get_vgcanvas(c);
    color_t color = style_get_color(widget->astyle, STYLE_ID_DRAGGER_COLOR, color_init(0, 0, 0, 0));

    if (color.rgba.a == 0) {
      color = style_get_color(widget->astyle, STYLE_ID_FG_COLOR, color_init(0, 0, 0, 0));
    }

    vgcanvas_draw_circle(vg, dragger_x, dragger_y, slider_circle->header_size, color, TRUE, FALSE);
  }

  if (slider_circle->show_text) {
    widget_set_text_with_double(widget, slider_circle->format, slider_circle->value);
    widget_paint_helper(widget, c, NULL, NULL);
  }

  return RET_OK;
}

static ret_t slider_circle_on_paint_background(widget_t* widget, canvas_t* c) {
  double r = 0;
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL && c != NULL, RET_BAD_PARAMS);
  r = tk_min(widget->w / 2, widget->h / 2) - slider_circle->bg_line_width / 2;

  widget_draw_arc_at_center(widget, c, TRUE, slider_circle->bg_line_width,
                            TK_D2R(slider_circle->start_angle), TK_D2R(slider_circle->end_angle),
                            FALSE, slider_circle->line_cap, r);

  return RET_OK;
}

static ret_t slider_circle_on_event(widget_t* widget, event_t* e) {
  uint16_t type = e->type;
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(widget != NULL && slider_circle != NULL, RET_BAD_PARAMS);

  switch (type) {
    case EVT_POINTER_DOWN: {
      pointer_event_t* pointer_event = pointer_event_cast(e);

      if (slider_circle_is_point_in_dragger(widget, pointer_event->x, pointer_event->y)) {
        widget_set_state(widget, WIDGET_STATE_PRESSED);
        widget_grab(widget->parent, widget);
        slider_circle->save_value = slider_circle->value;
        slider_circle->prev_value = slider_circle->value;
        slider_circle->dragging = TRUE;
      }

      break;
    }
    case EVT_POINTER_DOWN_ABORT: {
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      widget_ungrab(widget->parent, widget);

      slider_circle->dragging = FALSE;
      slider_circle->value = slider_circle->save_value;
      break;
    }
    case EVT_POINTER_UP: {
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      widget_ungrab(widget->parent, widget);
      slider_circle->dragging = FALSE;

      if (slider_circle->save_value != slider_circle->value) {
        slider_circle_set_value_internal(widget, slider_circle->value, EVT_VALUE_CHANGED, TRUE);
      }

      break;
    }
    case EVT_POINTER_MOVE: {
      pointer_event_t* pointer_event = pointer_event_cast(e);
      if (slider_circle->dragging) {
        double value = slider_circle_point_to_value(widget, pointer_event->x, pointer_event->y);

        slider_circle->prev_value = value;
        slider_circle_set_value_internal(widget, value, EVT_VALUE_CHANGING, FALSE);

        log_debug("value:%f\n", slider_circle->value);
        widget_set_state(widget, WIDGET_STATE_PRESSED);
        widget_invalidate(widget, NULL);
        return RET_STOP;
      } else {
        widget_set_state(widget, WIDGET_STATE_OVER);
      }
      break;
    }
    case EVT_POINTER_LEAVE:
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      break;
    case EVT_POINTER_ENTER:
      widget_set_state(widget, WIDGET_STATE_OVER);
      break;
    default:
      break;
  }

  return RET_OK;
}

const char* s_slider_circle_properties[] = {SLIDER_CIRCLE_PROP_VALUE,
                                            SLIDER_CIRCLE_PROP_MIN,
                                            SLIDER_CIRCLE_PROP_MAX,
                                            SLIDER_CIRCLE_PROP_STEP,
                                            SLIDER_CIRCLE_PROP_START_ANGLE,
                                            SLIDER_CIRCLE_PROP_END_ANGLE,
                                            SLIDER_CIRCLE_PROP_FG_LINE_WIDTH,
                                            SLIDER_CIRCLE_PROP_BG_LINE_WIDTH,
                                            SLIDER_CIRCLE_PROP_HEADER_SIZE,
                                            SLIDER_CIRCLE_PROP_DRAGGER_SIZE,
                                            SLIDER_CIRCLE_PROP_LINE_CAP,
                                            SLIDER_CIRCLE_PROP_COUNTER_CLOCK_WISE,
                                            SLIDER_CIRCLE_PROP_SHOW_TEXT,
                                            SLIDER_CIRCLE_PROP_FORMAT,
                                            NULL};

TK_DECL_VTABLE(slider_circle) = {.size = sizeof(slider_circle_t),
                                 .inputable = TRUE,
                                 .type = WIDGET_TYPE_SLIDER_CIRCLE,
                                 .clone_properties = s_slider_circle_properties,
                                 .persistent_properties = s_slider_circle_properties,
                                 .parent = TK_PARENT_VTABLE(widget),
                                 .create = slider_circle_create,
                                 .on_paint_self = slider_circle_on_paint_self,
                                 .on_paint_background = slider_circle_on_paint_background,
                                 .set_prop = slider_circle_set_prop,
                                 .get_prop = slider_circle_get_prop,
                                 .on_event = slider_circle_on_event,
                                 .on_destroy = slider_circle_on_destroy};

widget_t* slider_circle_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  widget_t* widget = widget_create(parent, TK_REF_VTABLE(slider_circle), x, y, w, h);
  slider_circle_t* slider_circle = SLIDER_CIRCLE(widget);
  return_value_if_fail(slider_circle != NULL, NULL);

  slider_circle->min = 0;
  slider_circle->max = 100;
  slider_circle->step = 1;
  slider_circle->value = 0;
  slider_circle->start_angle = 90;
  slider_circle->end_angle = 450;
  slider_circle->fg_line_width = 2;
  slider_circle->bg_line_width = 8;
  slider_circle->header_size = 8;
  slider_circle->dragger_size = 10;
  slider_circle->show_text = TRUE;
  slider_circle->format = tk_strdup("%d");

  return widget;
}

widget_t* slider_circle_cast(widget_t* widget) {
  return_value_if_fail(WIDGET_IS_INSTANCE_OF(widget, slider_circle), NULL);

  return widget;
}
