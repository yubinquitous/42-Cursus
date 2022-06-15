/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:27:10 by yubin             #+#    #+#             */
/*   Updated: 2022/06/15 17:00:48 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libgnl/get_next_line.h"
#include <stdio.h>

void  do_command(t_dual_stack *ds)
{
    char    *command;

    while (1)
    {
        command = get_next_line(0);
        while (!command)
            break;
        printf("command : %s\n", command);
        free(command);
    }
    
}  

int main(int argc, char** argv)
{
    t_dual_stack    ds;
    int             cnt;

    if (argc < 2)
        return (0);
    cnt = count_args(argc, argv);
    init_stack(argc, argv, cnt, &ds);
    if (stack_is_sorted(ds.a))
        return (0);
    do_command(&ds);
}