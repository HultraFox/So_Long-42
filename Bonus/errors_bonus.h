/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:34 by fmontel           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:37 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

# define _YB "\033[1;33m"
# define _CB "\033[1;36m"
# define _RB "\033[1;31m"
# define _WB "\033[1m"
# define _YY "\033[0;93m"
# define _CC "\033[0;96m"
# define _RR "\033[0;91m"
# define _Y_ "\033[0;33m"
# define _C_ "\033[0;36m"
# define _R_ "\033[0;31m"
# define _W_ "\033[0m"
//------------------------------
# define ERR_X "There was an Unknown Error:"
# define INF_X "No idea what broke, but here's the error code: "
# define ERR_Z "There was a Fake Error:"
# define INF_Z "This is how errors should look and give some infos :)"
# define ERR_0 "There was a Malloc Error:"
# define INF_0 "A malloc was not set properly, error code: "
# define ERR_1 "There was a Loading Error:"
# define INF_1 "An file can't be found or read: "
# define ERR_2 "There was an Over / Underflowed Error:"
# define INF_2 "Somehow, a value is not in the right place, error code: "
# define ERR_3 "There was a File Error:"
# define INF_3 "Empty address of file, error code: "
# define ERR_4 "There was a Map Error:"
# define INF_4_1 "Could not read map file: "
# define INF_4_2 ", error code: "
# define INF_5_1 "Error in map file: "
# define INF_5_2 ", the map is not a rectangle or use incorrect character(s): "
# define INF_5_4 ", the map is too large. Error code: "
# define INF_6_1 ", incorrect ammount of character (P/E/C/N) in the map file"
# define INF_6_6 ", empty map file"
# define INF_7_1 "File loaded as map does not posses .ber extention: "
# define INF_8_1 "Can't reach the exit of the map file: "
# define ERR_11 "There was an Error with the config file:"
# define INF_11 "It is suggested to just delete it. Error code: "
//------------------------------
# define ERR_C_1 "	*10xx : Could not find or open file:\n"
# define ERR_C_11 "		*01    : Can't open file at given adress;\n"
# define ERR_C_12 "		*02-04 : Slime / Map / Object texture was not found;\n"
# define ERR_C_15 "		*05    : dialogue contain a non multiple of 4 lines;\n"
# define ERR_C_16 "		*06    : dialogue contain an empty line;\n"
# define ERR_C_2 "	*20xx : Value Overflow:\n"
# define ERR_C_21 "		*01-03 : Skin-value Overflow;\n"
# define ERR_C_24 "		*04    : Scene-playing order Overflow;\n"
# define ERR_C_25 "		*05    : Scene-playing order Underflow;\n"
# define ERR_C_26 "		*06    : Can't reach next scene from \"from-black\";\n"
# define ERR_C_3 "	*30xx : Empty file adress;\n"
# define ERR_C_4 "	*40xx : Could not open or read .ber file;\n"
# define ERR_C_5 "	*50xx : Wrong map shape or incorrect character;\n"
# define ERR_C_6 "	*60xx : Incorrect number of special characters:\n"
# define ERR_C_61 "		*01   : No player, exit or collectible;\n"
# define ERR_C_62 "		*02   : 2 or more player starting positions;\n"
# define ERR_C_63 "		*03   : 2 or more exits;\n"
# define ERR_C_64 "		*04   : Can't reach all collectibles in the map;\n"
# define ERR_C_65 "		*05   : Too many Enemies on the map;\n"
# define ERR_C_66 "		*06   : Empty map file;\n"
# define ERR_C_7 "	*70xx : File is does not have .ber extention;\n"
# define ERR_C_8 "	*80xx : Player can't reach the exit of the map file;\n"
# define ERR_C_9 "	*90xx : Probleme while creating a malloc;\n"
# define ERR_C_110 "	*11xx : Unreadable config file;\n"

#endif