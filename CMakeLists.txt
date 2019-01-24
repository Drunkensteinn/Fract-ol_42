cmake_minimum_required(VERSION 3.12)
project(Fract_ol C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")
set(SOURCE_FILES src/main.c includes/fractol.h src/key_events.c src/drawing.c src/print.c src/init.c src/mandatory_fractals.c src/utils.c src/colors.c includes/fractol_keys.h src/mouse_events.c src/bonus_fractals.c src/fractal.c src/clean.c src/key_utils.c src/init_norme.c)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC})

add_executable(Fract_ol ${SOURCE_FILES})

target_link_libraries(Fract_ol ft)
