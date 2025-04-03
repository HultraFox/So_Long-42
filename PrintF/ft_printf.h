/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:40 by fmontel           #+#    #+#             */
/*   Updated: 2024/10/18 11:23:39 by fmontel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
size_t			ft_strlen(const char *s);
int				ft_charchk(char c, char const *set);
void			ft_putstr(char *s);
void			ft_putnbr(int nb);
void			ft_puthex(unsigned int nb, int uppc);
size_t			ft_puthex_adrs(size_t nb);
void			ft_u_putnbr(unsigned int nb);
int				ft_putlstr(char *s);
int				ft_putlnbr(int nb);
unsigned int	ft_putlhex(unsigned int nb, int uppc);
size_t			ft_putlhex_adrs(size_t nb);
unsigned int	ft_u_putlnbr(unsigned int nb);

#endif
