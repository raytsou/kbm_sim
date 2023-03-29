# kbm_sim
Node for taking in rosmsgs and outputting keyboard and mouse events.

Mouse button numbers:

http://xahlee.info/linux/linux_x11_mouse_button_number.html

Keyboard mapping:
https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

# Events.msg

- string[] keys_down
- string[] keys_up
- float64 mouse_move_x
- float64 mouse_move_y
- uint32[] mouse_click
- uint32[] mouse_release
