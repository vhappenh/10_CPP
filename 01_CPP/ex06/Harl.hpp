/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:55:11 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/14 11:29:39 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>


class Harl
{
private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
public:
    Harl(void);
    ~Harl(void);  
    void complain(std::string level); 
} ;

#endif