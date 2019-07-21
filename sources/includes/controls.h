#ifndef CONTROLS_H
# define CONTROLS_H

# define YES 1
# define NO 0

# define KB_STD_PLUS 24
# define KB_NUM_PLUS 69

# define KB_STD_MINUS 27
# define KB_NUM_MINUS 78

# define KB_KEY_LEFT 123
# define KB_KEY_RIGHT 124
# define KB_KEY_UP 126
# define KB_KEY_DOWN 125

# define KB_KEY_I 34
# define KB_KEY_P 35

# define KB_NUM_6 88
# define KB_NUM_4 86
# define KB_NUM_8 91
# define KB_NUM_5 87

# define KB_NUM_7 89
# define KB_NUM_9 92

# define KB_KEY_Z_PLS 33
# define KB_KEY_Z_MNS 30

# define KB_KEY_ARR_LEFT 43
# define KB_KEY_ARR_RIGHT 47

# define MS_LFT_BTN 1
# define MS_RGHT_BTN 2

# define MS_SCRL_UP 5
# define MS_SCRL_DWN 4

typedef struct		s_cntrls
{
	char			rght_prssd;
	char			lft_prssd;
	int				strt_x;
	int				strt_y;
	int				prev_x;
	int				prev_y;
}					t_cntrls;

#endif
