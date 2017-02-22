/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:06:00 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/22 14:50:33 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"

int			fis__read(t_fis *self, size_t n)
{
	int				ret;

	fta_reserve(&self->buff, n);
	ret = read(self->fd, ARRAY_END(&self->buff), n);
	if (ret >= 0)
		self->buff.size += ret;
	return (ret);
}

t_substr	fis_read(t_is *self, size_t n)
{
	t_fis *const	this = (t_fis *)self;

	if (n > this->buff.size)
		ret = fis__read(this, n - this->buff.size);
	n = MIN(n, this->buff.size);
	return ();
}

t_substr	sis_read(t_is *self)
{
	t_sis *const		this = (t_sis *)self;
}