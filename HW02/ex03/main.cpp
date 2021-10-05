/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:08:47 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/05 20:50:56 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CircularlyLinkedList.hpp"
#include "Student.hpp"
#include "../../libft/libft.hpp"

Student	*ft_create_student(std::string line)
{
	int			i;
	std::string	name;
	int			questions;

	if (line.length() < 3)
		return (NULL);
	i = line.length() - 1;
	while (ft_isdigit(line[i]))
		i--;
	if (i == (int)line.length() - 1 || line[i] != ' ')
		return (NULL);
	questions = ft_atoi(line.substr(i + 1).c_str());
	if (!questions)
		return (NULL);
	name = line.substr(0, i);
	return (new Student(name, questions));
}

/*
 * USE Ctrl+D TO SIGNAL THE END OF INPUT
 */
int	main(void)
{
	int								size;
	std::string						input;
	Student							*stud;
	CircularlyLinkedList<Student>	*students;
	CircularlyLinkedList<Student>	*reversed_students;

	size = 0;
	reversed_students = new CircularlyLinkedList<Student>();
	while (std::getline(std::cin, input))
	{
		stud = ft_create_student(input);
		if (!stud)
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		reversed_students->add(*stud);
		size++;
	}
	students = new CircularlyLinkedList<Student>();
	while (size > 0)
	{
		students->add(reversed_students->front());
		reversed_students->advance();
		size--;
	}
	while (!students->empty())
	{
		students->front().printName();
		std::cout << " asks question ";
		students->front().printCurrent();
		std::cout << std::endl;
		students->front().incrementCurrent();
		if (students->front().getCurrent() > students->front().getQuestions())
			students->remove();
		else
			students->advance();
	}
	delete students;
}
