cmake_minimum_required(VERSION 3.12)
project(Fract_ol C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")
set(SOURCE_FILES main.c fractol.h key_events.c drawing.c print.c init.c mandatory_fractals.c utils.c colors.c fractol_keys.h mouse_events.c bonus_fractals.c fractal.c clean.c key_utils.c init_norme.c)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC})

add_executable(Fract_ol ${SOURCE_FILES})

target_link_libraries(Fract_ol ft)
