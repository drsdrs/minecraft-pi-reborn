#ifndef INPUT_H

#define INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

void input_key_press(char key);
void input_clear_input();

void input_set_is_right_click(int val);
void input_hide_gui();
void input_third_person();

void input_set_is_left_click(int val);

void init_input_cpp();

#ifdef __cplusplus
}
#endif

#endif
