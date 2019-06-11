#include <mlx.h>

int main()
{
	void *m_ptr;
	void *w_ptr;

	m_ptr = mlx_init();
	w_ptr = mlx_new_window(m_ptr, 500, 500, "fdf");
	int ct;
	ct = 0;
	while (ct++ < 499)
		mlx_pixel_put (m_ptr, w_ptr, ct, ct, 0255255255);
	mlx_loop(m_ptr);
	return (0);
}
