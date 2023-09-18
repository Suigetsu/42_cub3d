// void drawLineDDA(int x1, int y1, int x2, int y2, mlx_image_t *img, t_cub3d *var) {
//     int dx = x2 - x1;
//     int dy = y2 - y1;

//     int steps;

//     if (abs(dx) > abs(dy)) {
//         steps = abs(dx);
//     } else {
//         steps = abs(dy);
//     }

//     float xIncrement = (float)dx / steps;
//     float yIncrement = (float)dy / steps;

//     float x = x1;
//     float y = y1;

//     for (int i = 0; i <= steps; i++) {
// 		if (x > 0 && x < var->x_max * T_SIZE && y > 0 && y < var->y_max * T_SIZE)
//         	mlx_put_pixel(img, x, y, 0x0000FFFF); // Assuming you're using a graphics library with putpixel function

//         x += xIncrement;
//         y += yIncrement;
//     }
// }
