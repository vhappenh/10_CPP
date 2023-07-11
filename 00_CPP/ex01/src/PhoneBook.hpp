/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:41:55 by vhappenh          #+#    #+#             */
/*   Updated: 2023/06/27 16:59:16 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _storage[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void Add(Contact contact, int i);
		void Search(int n);
};

#endif