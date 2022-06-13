#include "../../includes/push_swap.h"

t_command init_command_list()
{
    t_command command_list;

    command_list.next = 0;
    command_list.prev = 0;
    command_list.command = HEAD;
    return command_list;
}

void delete_command(t_command *command_list)
{
    command_list->next = command_list->next->next;
    if (command_list->next)
        command_list->next->prev = command_list;
}

void add_command(t_command *command_list, int command)
{
    t_command new_node;

    new_node.command = command;
    new_node.next = command_list->next;
    new_node.prev = command_list;
    command_list->next = &new_node;
    if (new_node.next)
        new_node.next->prev = &new_node;
    combine_command(command_list);
}

void combine_command(t_command *command_list)
{
    t_command *left;
    t_command *right;

    left = command_list->next;
    right = left->next;
    if (!right)
        return;
    if ((left->command == RA && right->command == RB) || (left->command == RB && right->command == RA))
    {
        delete_command(command_list);
        delete_command(command_list);
        add_command(command_list, RR);
    }
    else if ((left->command == RRA && right->command == RRB) || (left->command == RRB && right->command == RRA))
    {
        delete_command(command_list);
        delete_command(command_list);
        add_command(command_list, RRR);
    }
    else if ((left->command == SA && right->command == SB) || (left->command == SB && right->command == SA))
    {
        delete_command(command_list);
        delete_command(command_list);
        add_command(command_list, SS);
    }
}

void do_command(t_dual_stack *ds)
{
    t_command *cur;
    int i;

    cur = ds->command.next;
    i = 0;
    while (cur->next != 0)
    {
        cur = cur->next;
        ++i;
    }
    while (--i)
    {
        if (cur->command == RA)
            write(1, "ra\n", 3);
        else if (cur->command == RB)
            write(1, "rb\n", 3);
        else if (cur->command == RR)
            write(1, "rr\n", 3);
        else if (cur->command == RRA)
            write(1, "rra\n", 4);
        else if (cur->command == RRB)
            write(1, "rrb\n", 4);
        else if (cur->command == RRR)
            write(1, "rrr\n", 4);
        else if (cur->command == SA)
            write(1, "sa\n", 3);
        else if (cur->command == PA)
            write(1, "pa\n", 3);
        else
            write(1, "pb\n", 3);
        cur = cur->prev;
    }
}