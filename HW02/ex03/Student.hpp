/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:27 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 18:31:07 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <string>
# include <iostream>

class	Student
{
	private:
		std::string			_name;
		int					_questions;
		int					_current;
		Student(void);
	public:
		Student(std::string &name, int questions);
		~Student(void);
		Student(const Student &copy);
		std::string			getName(void)		const;
		int					getQuestions(void)	const;
		int					getCurrent(void)	const;
		void				printName(void)		const;
		void				printCurrent(void)	const;
		void				incrementCurrent(void);
};

#endif