#include "slider_circle/slider_circle.h"
#include "gtest/gtest.h"

TEST(slider_circle, basic) {
  widget_t* w = slider_circle_create(NULL, 10, 20, 100, 100);
  slider_circle_t* s = (slider_circle_t*)w;

  ASSERT_EQ(slider_circle_set_bg_line_width(w, 10), RET_OK);
  ASSERT_EQ(s->bg_line_width, 10);

  ASSERT_EQ(slider_circle_set_fg_line_width(w, 10), RET_OK);
  ASSERT_EQ(s->fg_line_width, 10);

  ASSERT_EQ(slider_circle_set_counter_clock_wise(w, true), RET_OK);
  ASSERT_EQ(s->counter_clock_wise, true);

  ASSERT_EQ(slider_circle_set_value(w, 0.5), RET_OK);
  ASSERT_EQ(s->value, 1);

  ASSERT_EQ(slider_circle_set_value(w, 10), RET_OK);
  ASSERT_EQ(s->value, 10);

  ASSERT_EQ(slider_circle_set_min(w, 11), RET_OK);
  ASSERT_EQ(s->min, 11);

  ASSERT_EQ(slider_circle_set_max(w, 100), RET_OK);
  ASSERT_EQ(s->max, 100);

  ASSERT_EQ(slider_circle_set_step(w, 10), RET_OK);
  ASSERT_EQ(s->step, 10);

  ASSERT_EQ(slider_circle_set_format(w, "%.2f"), RET_OK);
  ASSERT_STREQ(s->format, "%.2f");

  ASSERT_EQ(slider_circle_set_dragger_size(w, 10), RET_OK);
  ASSERT_EQ(s->dragger_size, 10);

  ASSERT_EQ(slider_circle_set_header_size(w, 10), RET_OK);
  ASSERT_EQ(s->header_size, 10);

  ASSERT_EQ(slider_circle_set_start_angle(w, 300), RET_OK);
  ASSERT_EQ(s->start_angle, 300);

  ASSERT_EQ(slider_circle_set_end_angle(w, 10), RET_OK);
  ASSERT_EQ(s->end_angle, 10);

  widget_destroy(w);
}

TEST(slider_circle, set_get) {
  widget_t* w = slider_circle_create(NULL, 10, 20, 100, 100);

  ASSERT_EQ(widget_set_prop_int(w, SLIDER_CIRCLE_PROP_BG_LINE_WIDTH, 10), RET_OK);
  ASSERT_EQ(widget_get_prop_int(w, SLIDER_CIRCLE_PROP_BG_LINE_WIDTH, 0), 10);

  ASSERT_EQ(widget_set_prop_int(w, SLIDER_CIRCLE_PROP_FG_LINE_WIDTH, 10), RET_OK);
  ASSERT_EQ(widget_get_prop_int(w, SLIDER_CIRCLE_PROP_FG_LINE_WIDTH, 0), 10);

  ASSERT_EQ(widget_set_prop_bool(w, SLIDER_CIRCLE_PROP_COUNTER_CLOCK_WISE, true), RET_OK);
  ASSERT_EQ(widget_get_prop_bool(w, SLIDER_CIRCLE_PROP_COUNTER_CLOCK_WISE, false), true);

  ASSERT_EQ(widget_set_prop_float(w, SLIDER_CIRCLE_PROP_VALUE, 0.5), RET_OK);
  ASSERT_EQ(widget_get_prop_float(w, SLIDER_CIRCLE_PROP_VALUE, 0), 1);

  ASSERT_EQ(widget_set_prop_float(w, SLIDER_CIRCLE_PROP_MIN, 11), RET_OK);
  ASSERT_EQ(widget_get_prop_float(w, SLIDER_CIRCLE_PROP_MIN, 0), 11);

  ASSERT_EQ(widget_set_prop_float(w, SLIDER_CIRCLE_PROP_MAX, 100), RET_OK);
  ASSERT_EQ(widget_get_prop_float(w, SLIDER_CIRCLE_PROP_MAX, 0), 100);

  ASSERT_EQ(widget_set_prop_float(w, SLIDER_CIRCLE_PROP_STEP, 10), RET_OK);
  ASSERT_EQ(widget_get_prop_float(w, SLIDER_CIRCLE_PROP_STEP, 0), 10);

  ASSERT_EQ(widget_set_prop_str(w, SLIDER_CIRCLE_PROP_FORMAT, "%.2f"), RET_OK);
  ASSERT_STREQ(widget_get_prop_str(w, SLIDER_CIRCLE_PROP_FORMAT, ""), "%.2f");

  ASSERT_EQ(widget_set_prop_int(w, SLIDER_CIRCLE_PROP_DRAGGER_SIZE, 10), RET_OK);
  ASSERT_EQ(widget_get_prop_int(w, SLIDER_CIRCLE_PROP_DRAGGER_SIZE, 0), 10);

  ASSERT_EQ(widget_set_prop_int(w, SLIDER_CIRCLE_PROP_HEADER_SIZE, 10), RET_OK);
  ASSERT_EQ(widget_get_prop_int(w, SLIDER_CIRCLE_PROP_HEADER_SIZE, 0), 10);

  ASSERT_EQ(widget_set_prop_int(w, SLIDER_CIRCLE_PROP_START_ANGLE, 300), RET_OK);
  ASSERT_EQ(widget_get_prop_int(w, SLIDER_CIRCLE_PROP_START_ANGLE, 0), 300);

  ASSERT_EQ(widget_set_prop_int(w, SLIDER_CIRCLE_PROP_END_ANGLE, 10), RET_OK);
  ASSERT_EQ(widget_get_prop_int(w, SLIDER_CIRCLE_PROP_END_ANGLE, 0), 10);

  widget_destroy(w);
}

TEST(slider_circle, others) {
  double angle = 0;
  widget_t* w = slider_circle_create(NULL, 10, 20, 100, 100);
  slider_circle_t* s = (slider_circle_t*)w;

  slider_circle_set_start_angle(w, 0);
  slider_circle_set_end_angle(w, 360);
  slider_circle_set_min(w, 10);
  slider_circle_set_max(w, 110);

  ASSERT_EQ(slider_circle_is_point_in_dragger(w, 10, 10), FALSE);
  ASSERT_EQ(slider_circle_is_point_in_dragger(w, 110, 70), TRUE);

  angle = slider_circle_point_to_angle(w, 110, 70);
  ASSERT_EQ(angle, 360);

  angle = slider_circle_point_to_angle(w, 110, 68);
  ASSERT_EQ(tk_roundi(angle), 358);

  angle = slider_circle_point_to_angle(w, 110, 72);
  ASSERT_EQ(tk_roundi(angle), 2);

  ASSERT_EQ(slider_circle_angle_to_value(w, 0), 10);

  s->prev_value = 109;
  ASSERT_EQ(slider_circle_angle_to_value(w, 360), 110);

  ASSERT_EQ(slider_circle_point_to_value(w, 110, 70), 110);
  ASSERT_EQ(slider_circle_point_to_value(w, 60, 20), 85);

  slider_circle_set_counter_clock_wise(w, true);
  ASSERT_EQ(slider_circle_point_to_value(w, 110, 70), 110);
  ASSERT_EQ(slider_circle_point_to_value(w, 60, 20), 35);

  widget_destroy(w);
}