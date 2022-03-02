#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

using namespace std;

// RowColumnClass related values
const int DEFAULT_ROW_COLUMN_VALUE = 0;
const int MIN_ROW_COLUMN_VALUE = 0;

// ColorClass related values
const int MIN_COLOR_MENU_NUMBER = 1;
const int MAX_COLOR_MENU_NUMBER = 5;
const int CHOICE_RED = 1;
const int CHOICE_GREEN = 2;
const int CHOICE_BLUE = 3;
const int CHOICE_BLACK = 4;
const int CHOICE_WHITE = 5;

// RectangleClass related values
const int DEFAULT_RECTANGLE_SIZE_VALUE = 0;
const int MIN_RECTANGLE_SIZE_VALUE = 0;
const int RECTANGLE_LOCATION_AND_SIZE_VALUES_COUNT = 4;
const int MIN_RECTANGLE_FILL_MENU_NUMBER = 1;
const int MAX_RECTANGLE_FILL_MENU_NUMBER = 2;
const int CHOICE_NO = 1;
const int CHOICE_YES = 2;

// PpmImageClass related values
const string PPM_IMAGE_MAGIC_NUMBER = "P3";
const int PPM_IMAGE_SIZE_VALUE_COUNT = 2;
const int MIN_PPM_IMAGE_SIZE_VALUE = 0;
const int MAX_PPM_IMAGE_VALUE = 255;
const int MIN_PPM_IMAGE_VALUE = 0;

// PatternClass related values
const int PATTERN_SIZE_VALUE_COUNT = 2;
const int MIN_PATTERN_SIZE_VALUE = 0;
const int MIN_PATTERN_VALUE = 0;
const int MAX_PATTERN_VALUE = 1;

// Values used in Main
const int MIN_MAIN_MENU_NUMBER = 1;
const int MAX_MAIN_MENU_NUMBER = 5;
const int MIN_RECTANGLE_SPECIFICATION_MENU_NUMBER = 1;
const int MAX_RECTANGLE_SPECIFICATION_MENU_NUMBER = 3;
const int DEFAULT_MAIN_MENU_NUMBER = 0;
const int CHOICE_ANNOTATE_RECTANGLE_MAIN_MENU = 1;
const int CHOICE_ANNOTATE_PATTERN_MAIN_MENU = 2;
const int CHOICE_INSERT_IMAGE_MAIN_MENU = 3;
const int CHOICE_WRITE_OUT_MAIN_MENU = 4;
const int CHOICE_EXIT_MAIN_MENU = 5;
const int CHOICE_SPECIFY_UPPER_LEFT_LOWER_RIGHT_METHOD = 1;
const int CHOICE_SPECIFY_UPPER_LEFT_DIMENSION_METHOD = 2;
const int CHOICE_SPECIFY_EXTENT_FROM_CENTER_METHOD = 3;

#endif
