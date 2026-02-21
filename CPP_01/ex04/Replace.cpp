/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:38:03 by jcosta-b          #+#    #+#             */
/*   Updated: 2026/01/10 14:38:04 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>

static std::string replaceContent(const std::string& content,
                                  const std::string& s1,
                                  const std::string& s2)
{
    std::string result;
    size_t position = 0;
    size_t found;

    while ((found = content.find(s1, position)) != std::string::npos)
    {
        result.append(content, position, found - position);
        result.append(s2);
        position = found + s1.length();
    }
    result.append(content, position);
    return result;
}

bool replaceFile(const std::string& filename,
                 const std::string& s1,
                 const std::string& s2)
{
    if (s1.empty())
        return false;

    std::ifstream infile(filename.c_str());
    if (!infile)
        return false;

    std::string content, line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
        return false;

    outfile << replaceContent(content, s1, s2);
    outfile.close();
    return true;
}