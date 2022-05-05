/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:00:41 by bbischof          #+#    #+#             */
/*   Updated: 2022/05/05 15:49:39 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

// Terminal colors
# define TERM_END "\x1b[0m"
# define TERM_RED "\x1b[31m"
# define TERM_GREEN "\x1b[32m"
# define TERM_BLUE "\x1b[34m"
# define TERM_ERASE "\033[2K\r"
# define TERM_BCKG_END "\x1b[0m"
# define TERM_BCKG_RED "\x1b[41m"
# define TERM_BCKG_GREEN "\x1b[42m"
# define TERM_BCKG_YELLOW "\x1b[43m"
# define TERM_BCKG_BLUE "\x1b[44m"
# define TERM_BCKG_MAGENTA "\x1b[45m"
# define TERM_BCKG_CYAN "\x1b[46m"
# define TERM_BCKG_WHITE "\x1b[47m"

// Keycode
// Mac
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MOUSE_WHELL 3
# define LMB 1
# define RMB 2
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_O 31
# define KEY_P 35
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_1 83
# define KEY_2 84
# define KEY_4 86
# define KEY_5 87
# define KEY_7 89
# define KEY_8 91
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

// Colors
# define WHITE 0x00FFFFFF
# define DARK_GRAY 0xFF333333
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define PURPLE 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define PINK 0x00DD88BB
# define LIGHT_BLUE 0x00AAAAFF
# define BACKGROUND 0xC0000000

// Palyer mouvment
# define SAFE_COL 0.2
# define MOVE_SPEED 0.15
# define ROT_SPEED 0.0698132

#endif