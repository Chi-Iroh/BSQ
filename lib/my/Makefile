##
## EPITECH PROJECT, 2022
## libmy Makefile
## File description:
## Wno-unused-parameter for unimplemented functions
##

CFLAGS	+=	-Wall -Wextra -pedantic -g3 -Wno-unused-parameter

SRC	=	./my_strcat.c 				        	\
		./my_convert_nbr_base.c 	        	\
		./my_strcpy.c 				        	\
		./char_traits.c 			        	\
		./my_isneg.c 				        	\
		./my_strncpy.c 				        	\
		./my_strstr.c 				        	\
		./my_strncmp.c 				        	\
		./my_getnbr.c 				        	\
		./my_find_prime_sup.c 		        	\
		./my_str_isnum.c 			        	\
		./my_string2.c 				        	\
		./my_compute_power_rec.c 	        	\
		./my_str_isalpha.c 			        	\
		./my_strchr.c 				        	\
		./my_string_append_str.c 	        	\
		./sort_int_array.c 			        	\
		./my_is_prime.c 			        	\
		./str_append.c 				        	\
		./my_strcmp.c 				        	\
		./my_str_to_word_array.c 	        	\
		./my_str_isupper.c 			        	\
		./my_strlen.c 				        	\
		./my_putchar.c 				        	\
		./my_showstr.c 				        	\
		./my_strncat.c 				        	\
		./my_strcapitalize.c 		        	\
		./my_revstr.c 				        	\
		./str_array.c 				        	\
		./my_strupcase.c 			        	\
		./my_swap.c 				        	\
		./my_strlowcase.c 			        	\
		./my_showmem.c 				        	\
		./my_put_nbr.c 				        	\
		./my_compute_square_root.c 	        	\
		./my_str_isprintable.c 		        	\
		./printf/flag_o.c 			        	\
		./printf/flag_a.c 			        	\
		./printf/my_wcalloc.c 		        	\
		./printf/convert_floats.c 	        	\
		./printf/my_wgetnbr.c 		        	\
		./printf/my_wprintf.c 		        	\
		./printf/convert_signed_integers.c      \
		./printf/convert_strings.c 			    \
		./printf/flag_a_core.c 				    \
		./printf/flag_di.c 					    \
		./printf/flag_b.c 					    \
		./printf/apply_modifiers.c 			    \
		./printf/float_core.c 				    \
		./printf/flag_g.c 					    \
		./printf/flag_s.c 					    \
		./printf/my_wgetnbr_core.c 			    \
		./printf/my_wputchar.c 				    \
		./printf/my_wstrstr.c 				    \
		./printf/flag_c.c 					    \
		./printf/my_wprintf2.c 				    \
		./printf/flag_n.c 					    \
		./printf/wchar_traits.c 			    \
		./printf/wstring_convert.c 			    \
		./printf/convert_pointers.c 		    \
		./printf/my_wstring.c 	                \
		./printf/my_printf.c                    \
		./printf/my_wstring2.c                  \
		./printf/my_wstrdup.c                   \
		./printf/parser.c                       \
		./printf/flag_f.c                       \
		./printf/flag_u.c                       \
		./printf/my_wputstr.c                   \
		./printf/flag_x.c                       \
		./printf/read_arg.c                     \
		./printf/flag_p.c                       \
		./printf/my_wstrlen.c                   \
		./printf/convert_unsigned_integers.c    \
		./printf/parser_set.c                   \
		./printf/flag_length.c                  \
		./printf/my_wputnbr_base.c              \
		./printf/flag_e.c                       \
		./printf/my_wstrcmp.c                   \
		./printf/call_flags.c                   \
		./my_str_islower.c                      \
		./my_putstr.c                           \
		./my_string.c                           \
		./my_get_nbr_core.c                     \
		./my_strdup.c                           \
		./my_calloc.c


OBJ	=	$(SRC:.c=.o)

all: $(OBJ)
	ar rc libmy.a $(OBJ)
	cp my.h my_macros.h printf/my_printf.h ../../include/
	cp libmy.a ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f libmy.a

re: fclean all
