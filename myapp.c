#include <stdio.h>
#include <string.h>


// Main Menu Functions Prototypes

void welcome_screen();
void main_menu_screen();
void main_menu();
int get_int();


// Event Menu Functions Prototypes

void event_menu_screen();
void event_menu();
void create_event();
void list_events();
void search_event();
void update_event();
void delete_event();
void load_events();
void update_events();


// Customer Menu Functions Prototypes

void customer_menu_screen();
void customer_menu();
void add_customer();
void list_customers();
void search_customer();
void update_customer();
void delete_customer();
void load_customers();
void update_customers();

// Ticket Menu Functions Prototypes

void ticket_menu_screen();
void ticket_menu();
void book_ticket();
void list_tickets();
void search_ticket();
void cancel_ticket();
void load_tickets();
void update_tickets();


// Organizer Menu Functions Prototypes

void organizer_menu_screen();
void organizer_menu();
void add_organizer();
void list_organizers();
void search_organizer();
void update_organizer();
void delete_organizer();
void load_organizers();
void update_organizers();


// Structures 

struct event
{
    char name[50];
    char venue[50];
    char date[20];
    char time[20];
    int total_tickets;
    int id;
};

struct customer
{
    char name[30];
    char phone[15];
    char email[30];
    // int event_id;
    // int ticket_id;
    int id;
};

struct ticket
{
    int seat_no;
    int price;
    int event_id;
    int customer_id;
    int id;
};

struct organizer
{
    char name[30];
    char phone[15];
    char company[30];
    int id;
};


// Global Arrays

struct event e[100];
int event_count = 0;

struct customer c[100];
int customer_count = 0;

struct ticket t[1000];
int ticket_count = 0;

struct organizer o[100];
int organizer_count = 0;


// Main Function

int main()
{
    load_events();
    load_customers();
    load_tickets();
    load_organizers();
    welcome_screen();
    main_menu();
    return 0;
}


// Main Menu Functions

void welcome_screen()
{
    printf("\033[33m------------------------------------------------\033[0m\n");
    printf("\033[33m***    Welcome to Event Management System    ***\033[0m\n");
    printf("\033[33m------------------------------------------------\033[0m\n\n");
}

void main_menu_screen()
{
    printf("\033[31m---------------------\033[0m\n");
    printf("\033[31m***   Main Menu   ***\033[0m\n");
    printf("\033[31m---------------------\033[0m\n");

    printf("\033[97m=====================\033[0m\n");
    printf("\033[97m1. Event Management\033[0m\n");
    printf("\033[97m2. Customer Management\033[0m\n");
    printf("\033[97m3. Ticket Management\033[0m\n");
    printf("\033[97m4. Organizer Management\033[0m\n");
    printf("\033[97m5. Exit the program\033[0m\n");
    printf("\033[97m=====================\033[0m\n\n");
}

void main_menu()
{
    while (1)
    {
        main_menu_screen();

        int choice;
        printf("\033[32mEnter your choice : \033[0m");
        choice = get_int();

        if (choice == -1)
        {
            printf("Press enter to go back to main menu: ");
            getchar();
            printf("\n");
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                event_menu();
                break;
            }
            case 2:
            {
                customer_menu();
                break;
            }
            case 3:
            {
                ticket_menu();
                break;
            }
            case 4:
            {
                organizer_menu();
                break;
            }
            case 5:
            {
                printf("\033[31m---------------------------------\033[0m\n");
                printf("\033[31m>>>   Thanks for your time!   <<<\033[0m\n");
                printf("\033[31m---------------------------------\033[0m\n");
                return;
            }
            default:
            {
                printf("Invalid choice...\n\n");
            }
        }
    }    
}

int get_int()
{
    int x;
    if (scanf("%d", &x) != 1)
    {
        printf("Invalid input! Please enter a number.\n\n");
        while(getchar() != '\n');
        return -1;
    }
    return x;
}


// Event Menu Functions

void event_menu_screen()          
{
    printf("\n\033[34m>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n");
    printf("\033[34m***    Event Menu    ***\033[0m\n");
    printf("\033[34m>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n");

    printf("---------------------\n");
    printf("1. Create Event\n");
    printf("2. List Events\n");
    printf("3. Search Event\n");
    printf("4. Update Event\n");
    printf("5. Delete Event\n");
    printf("6. Back to main menu\n");
    printf("---------------------\n\n");
}

void event_menu()
{
    while (1)
    {
        event_menu_screen();
        int event_choice;
        printf("\033[32mEnter your choice : \033[0m");
        event_choice = get_int();

        if (event_choice == -1)
        {
            printf("Press enter to go back to event menu: ");
            getchar();
            printf("\n");
            continue;
        }

        switch (event_choice)
        {
            case 1:
            {
                create_event();
                break;
            }
            case 2:
            {
                list_events();
                break;
            }
            case 3:
            {
                search_event();
                break;
            }
            case 4:
            {
                update_event();
                break;
            }
            case 5:
            {
                delete_event();
                break;
            }
            case 6:
            {
                printf("\n");
                return;
            }
            default:
            {
                printf("Invalid choice...\n\n");
            }
        }
        printf("Press enter to go back to event menu: ");
        getchar();
        getchar();
        printf("\n");
    }    
}

void create_event()
{
    printf("---------------------------------------------------------\n");
    printf("\033[31mTo create an event you have to enter your organizer id...\033[0m\n\n");
    int choice;
    while (1)
    {
        printf("Enter 1 to create organizer id or Enter 2 to contninue: ");
        if (scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n');
            continue;
        }
        break; 
    }

    switch (choice)
    {
        case 1:
        {
            printf("\n");
            add_organizer();
            printf("Press enter to continue the process of creating event: ");
            getchar();
            getchar();
            printf("\n");
            break;
        }
        case 2:
        {
            printf("\n");
            break;
        }
        default:
        {
            printf("Invalid choice!\n");
        }
    }

    
    int organizer_id;
    while (1)
    {
        printf("Enter Organizer ID: ");
        if (scanf("%d", &organizer_id) != 1)
        {
            while(getchar() != '\n');
            continue;
        }
        break;
    }
    if (organizer_count == 0 )
    {
        printf("Organizer not found!\n");
        return;
    }
    else if (organizer_id <= 0 || organizer_id > organizer_count)
    {
        printf("Invalid Organizer id!\n");
        return;
    }

    for (int i = 0; i < organizer_count; i++)
    {
        if (organizer_id == o[i].id)
        {
            printf("\n");
            printf("Event Name: ");
            scanf(" %49[^\n]", e[event_count].name);
            printf("Event Venue: ");
            scanf(" %49[^\n]", e[event_count].venue);
            printf("Event Date: ");
            scanf(" %19[^\n]", e[event_count].date);
            printf("Event Time: ");
            scanf(" %19[^\n]", e[event_count].time);
            while (1)
            {
                printf("Total Tickets: ");
                if (scanf("%d", &e[event_count].total_tickets) != 1)
                {
                    while(getchar() != '\n');
                    continue;
                }
                break;
            }
            e[event_count].id = event_count + 1;
            printf("----------------------------------------\n");
            printf("\033[93mYou have successfully create an event...\033[0m\n");
            printf("\033[93mYour event id is %d\033[0m\n", e[event_count].id);
            printf("----------------------------------------\n");

            FILE* event_file = fopen("event.txt", "a");
            fprintf(event_file, "%d|%s|%s|%s|%s|%d\n", e[event_count].id, e[event_count].name, e[event_count].venue, e[event_count].date, e[event_count].time, e[event_count].total_tickets);
            fclose(event_file);
            event_count ++;
        }
    }
}

void list_events()
{
    if (event_count == 0)
    {
        printf("No event added yet!\n");
        return;
    }
    printf("\n\n");
    printf("%-10s %-25s %-25s %-15s %-15s %-15s\n", "Event ID", "Name", "Venue", "Date", "Time", "Total Tickets");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int s = 0; s < event_count; s++)
    {
        printf("%-10d %-25s %-25s %-15s %-15s %-15d\n", e[s].id, e[s].name, e[s].venue, e[s].date, e[s].time, e[s].total_tickets);
    }
    printf("\n\n");
}

void search_event()
{
    if (event_count == 0)
    {
        printf("No event added yet!\n");
        return;
    }

    
    int event_id_user;
    while(1)
    {
        printf("Enter Event id: ");
        if (scanf("%d", &event_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (event_id_user <= 0 || event_id_user > event_count)
    {
        printf("No event found!\n");
    }
    else
    {
        for (int i = 0; i < event_count; i ++)
        {
            if (e[i].id == event_id_user)
            {
                printf("--------------------------------\n");
                printf("Event ID: %d\n", e[i].id);
                printf("Event Name: %s\n", e[i].name);
                printf("Event Venue: %s\n", e[i].venue);
                printf("Event Date: %s\n", e[i].date);
                printf("Event Time: %s\n", e[i].time);
                printf("Total Tickets: %d\n", e[i].total_tickets);
                printf("--------------------------------\n\n");
                return;
            }
        }
    }
}

void update_event()
{
    if (event_count == 0)
    {
        printf("No event added yet!\n");
        return;
    }

    int event_id_user;

    while(1)
    {
        printf("Enter Event ID: ");
        if (scanf("%d", &event_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (event_id_user <= 0 || event_id_user > event_count)
    {
        printf("No event found!");
    }
    else
    {
        for (int i = 0; i < event_count; i ++)
        {
            if (e[i].id == event_id_user)
            {
                printf("--------------------------------\n");
                printf("Event ID: %d\n", e[i].id);
                printf("Event Name: %s\n", e[i].name);
                printf("Event Venue: %s\n", e[i].venue);
                printf("Event Date: %s\n", e[i].date);
                printf("Event Time: %s\n", e[i].time);
                printf("Total Tickets: %d\n", e[i].total_tickets);
                printf("--------------------------------\n\n");

                printf("Event Name: ");
                scanf(" %49[^\n]", e[i].name);
                printf("Event Venue: ");
                scanf(" %49[^\n]", e[i].venue);
                printf("Event Date: ");
                scanf(" %19[^\n]", e[i].date);
                printf("Event Time: ");
                scanf(" %19[^\n]", e[i].time);
                while (1)
                {
                    printf("Total Tickets: ");
                    if (scanf("%d", &e[i].total_tickets) != 1)
                    {
                        while(getchar() != '\n');
                        continue;
                    }
                    break;
                }
                update_events();
                printf("Event has been updated successfully!\n\n");
                return;
            }
        }
    }
}

void delete_event()
{
    if (event_count == 0)
    {
        printf("No event added yet!\n");
        return;
    }

    int event_id_user;

    while(1)
    {
        printf("Enter Event ID: ");
        if (scanf("%d", &event_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (event_id_user <= 0 || event_id_user > event_count)
    {
        printf("No event found!\n");
    }
    else
    {
        for (int i = 0; i < event_count; i++)
        {
            if (event_id_user  == e[i].id)
            {
                for (int j = i; j < event_count - 1; j++)
                {
                    e[j] = e[j + 1];
                    e[j].id = j + 1;
                }
                event_count--;
                update_events();
                printf("Event has been deleted successfully...\n\n");
                return;
            }
        }
    }
}

void load_events()
{
    FILE* event_file = fopen("event.txt","r");
    if (event_file == NULL)
    {
        return;
    }
    while (fscanf(event_file, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%d", &e[event_count].id, e[event_count].name, e[event_count].venue, e[event_count].date, e[event_count].time, &e[event_count].total_tickets) != EOF)
    {
        event_count++;
    }
    fclose(event_file);
}

void update_events()
{
    FILE *event_file = fopen("event.txt", "w");

    for (int i = 0; i < event_count; i++)
    {
        fprintf(event_file, "%d|%s|%s|%s|%s|%d\n", e[i].id, e[i].name, e[i].venue, e[i].date,e[i].time, e[i].total_tickets);
    }
    fclose(event_file);
}

// Customer Menu Functiona

void customer_menu_screen()          
{
    printf("\n\033[34m>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n");
    printf("\033[34m***    Customer Menu    ***\033[0m\n");
    printf("\033[34m>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n");

    printf("---------------------\n");
    printf("1. Add Customer\n");
    printf("2. Search Customer\n");
    printf("3. List Customers\n");
    printf("4. Update Customer\n");
    printf("5. Delete Customer\n");
    printf("6. Back to main menu\n");
    printf("---------------------\n\n");
}

void customer_menu()
{
    while (1)
    {
        customer_menu_screen();
        int choice;
        printf("\033[32mEnter your choice : \033[0m");
        choice = get_int();

        if (choice == -1)
        {
            printf("Press enter to go back to customer menu: ");
            getchar();
            printf("\n");
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                add_customer();
                break;
            }
            case 2:
            {
                list_customers();
                break;
            }
            case 3:
            {
                search_customer();
                break;
            }
            case 4:
            {
                update_customer();
                break;
            }
            case 5:
            {
                delete_customer();
                break;
            }
            case 6:
            {
                printf("\n");
                return;
            }
            default:
            {
                printf("Invalid choice...\n\n");
            }
        }
        printf("Press enter to go back to customer menu: ");
        getchar();
        getchar();
        printf("\n\n");
    }    
}

void add_customer()
{
    printf("Customer Name: ");
    scanf(" %29[^\n]", c[customer_count].name);
    printf("Customer Phone: ");
    scanf(" %14[^\n]", c[customer_count].phone);
    printf("Customer Email: ");
    scanf(" %29[^\n]", c[customer_count].email);

    // while (1)
    // {
    //     printf("Event ID: ");
    //     if (scanf("%d", &c[customer_count].event_id) != 1)
    //     {
    //         while(getchar() != '\n');
    //         continue;
    //     }
    //     break;
    // }
    // while (1)
    // {
    //     printf("Ticket ID: ");
    //     if (scanf("%d", &c[customer_count].ticket_id) != 1)
    //     {
    //         while(getchar() != '\n');
    //         continue;
    //     }
    //     break;
    // }
    c[customer_count].id = customer_count + 1;
    printf("----------------------------------------\n");
    printf("\033[93mYou have successfully add a customer...\033[0m\n");
    printf("\033[93mCustomer id is %d\033[0m\n", c[customer_count].id);
    printf("----------------------------------------\n");
    FILE* customer_file = fopen("customer.txt", "a");
    fprintf(customer_file, "%d|%s|%s|%s\n", c[customer_count].id, c[customer_count].name, c[customer_count].phone, c[customer_count].email);
    fclose(customer_file);
    customer_count ++;
}

void search_customer()
{
    if (customer_count == 0)
    {
        printf("No customer found!\n\n");
        return;
    }

    int customer_id_user;
    while(1)
    {
        printf("Enter Customer id: ");
        if (scanf("%d", &customer_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (customer_id_user <= 0 || customer_id_user > customer_count)
    {
        printf("No customer found!\n");
    }
    else
    {
        for (int i = 0; i < customer_count; i ++)
        {
            if (c[i].id == customer_id_user)
            {
                printf("--------------------------------\n");
                printf("Customer ID: %d\n", c[i].id);
                printf("Customer Name: %s\n", c[i].name);
                printf("Customer Phone: %s\n", c[i].phone);
                printf("Customer Email: %s\n", c[i].email);
                // printf("Customer Event ID: %d\n", c[i].event_id);
                // printf("Customer Ticket ID: %d\n", c[i].ticket_id);
                printf("--------------------------------\n\n");
                return;
            }
        }
    }
}

void list_customers()
{
    if (customer_count == 0)
    {
        printf("No customer added yet!");
        return;
    }
    printf("\n\n");
    printf("%-15s %-25s %-15s %-25s\n", "Customer ID", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int s = 0; s < customer_count; s++)
    {
        printf("%-15d %-25s %-15s %-25s\n", c[s].id, c[s].name, c[s].phone, c[s].email);
    }
    printf("\n\n");
}

void update_customer()
{
    if (customer_count == 0)
    {
        printf("No customer found!");
        return;
    }

    int customer_id_user;

    while(1)
    {
        printf("Enter Customer ID: ");
        if (scanf("%d", &customer_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (customer_id_user <= 0 || customer_id_user > customer_count)
    {
        printf("No customer found!\n");
    }
    else
    {
        for (int i = 0; i < customer_count; i ++)
        {
            if (c[i].id == customer_id_user)
            {
                printf("--------------------------------\n");
                printf("Customer ID: %d\n", c[i].id);
                printf("Customer Name: %s\n", c[i].name);
                printf("Customer Phone: %s\n", c[i].phone);
                printf("Customer Email: %s\n", c[i].email);
                // printf("Customer Event ID: %d\n", c[i].event_id);
                // printf("Customer Ticket ID: %d\n", c[i].ticket_id);
                printf("--------------------------------\n\n");

                printf("Customer Name: ");
                scanf(" %29[^\n]", c[i].name);
                printf("Customer Phone: ");
                scanf(" %14[^\n]", c[i].phone);
                printf("Customer Email: ");
                scanf(" %29[^\n]", c[i].email);
                // while (1)
                // {
                //     printf("Event ID: ");
                //     if (scanf("%d", &c[i].event_id) != 1)
                //     {
                //         while(getchar() != '\n');
                //         continue;
                //     }
                //     break;
                // }
                // while (1)
                // {
                //     printf("Ticket ID: ");
                //     if (scanf("%d", &c[i].ticket_id) != 1)
                //     {
                //         while(getchar() != '\n');
                //         continue;
                //     }
                //     break;
                // }
                update_customers();
                printf("Customer has been updated successfully!\n\n");
                return;
            }
        }
    }
}

void delete_customer()
{
    if (customer_count == 0)
    {
        printf("No customer found!");
        return;
    }

    int customer_id_user;

    while(1)
    {
        printf("Enter Customer ID: ");
        if (scanf("%d", &customer_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (customer_id_user <= 0 || customer_id_user > customer_count)
    {
        printf("No customer found!\n");
    }
    else
    {
        for (int i = 0; i < customer_count; i++)
        {
            if (customer_id_user  == c[i].id)
            {
                for (int j = i; j < customer_count - 1; j++)
                {
                    c[j] = c[j + 1];
                    c[j].id = j + 1;
                }
                customer_count--;
                update_customers();
                printf("Customer has been deleted successfully...\n\n");
                return;
            }
        }
    }
}

void load_customers()
{
    FILE* customer_file = fopen("customer.txt","r");
    if (customer_file == NULL)
    {
        return;
    }
    while (fscanf(customer_file, "%d|%[^|]|%[^|]|%[^\n]", &c[customer_count].id, c[customer_count].name, c[customer_count].phone, c[customer_count].email) != EOF)
    {
        customer_count++;
    }
    fclose(customer_file);
}

void update_customers()
{
    FILE *customer_file = fopen("customer.txt", "w");

    for (int i = 0; i < customer_count; i++)
    {
        fprintf(customer_file, "%d|%s|%s|%s\n", c[i].id, c[i].name, c[i].phone, c[i].email);
    }     
    fclose(customer_file);
}

// Ticket Menu Functions

void ticket_menu_screen()          
{
    printf("\n\033[34m>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n");
    printf("\033[34m***    Ticket Menu    ***\033[0m\n");
    printf("\033[34m>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n");

    printf("---------------------\n");
    printf("1. Book Ticket\n");
    printf("2. List Tickets\n");
    printf("3. Search Ticket\n");
    printf("4. Cancel Ticket\n");
    printf("5. Back to main menu\n");
    printf("---------------------\n\n");
}

void ticket_menu()
{
    while (1)
    {
        ticket_menu_screen();
        int choice;
        printf("\033[32mEnter your choice : \033[0m");
        choice = get_int();

        if (choice == -1)
        {
            printf("Press enter to go back to ticket menu: ");
            getchar();
            printf("\n");
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                book_ticket();
                break;
            }
            case 2:
            {
                list_tickets();
                break;
            }
            case 3:
            {
                search_ticket();
                break;
            }
            case 4:
            {
                cancel_ticket();
                break;
            }
            case 5:
            {
                printf("\n");
                return;
            }
            default:
            {
                printf("Invalid choice...\n\n");
            }
        }
        printf("Press enter to go back to ticket menu: ");
        getchar();
        getchar();
        printf("\n\n");
    }    
}

void book_ticket()
{
    printf("------------------------------------------------------\n");
    printf("To book a ticket you have to enter your customer id...\n\n");
    int choice;
    while (1)
    {
        printf("Enter 1 to create customer id or Enter 2 to contninue: ");
        if (scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n');
            continue;
        }
        break; 
    }

    switch (choice)
    {
        case 1:
        {
            printf("\n");
            add_customer();
            printf("Press enter to continue the process of booking ticket: ");
            getchar();
            getchar();
            break;
        }
        case 2:
        {
            break;
        }
        default:
        {
            printf("Invalid choice!\n");
        }
    }
    int customer_id;
    while (1)
    {
        printf("\n");
        printf("Customer ID: ");
        if (scanf("%d", &customer_id) != 1)
        {
            while(getchar() != '\n');
            continue;
        }
        break;
    }
    if (customer_count == 0 )
    {
        printf("Customer not found!\n");
        return;
    }
    else if (customer_id <= 0 || customer_id > customer_count)
    {
        printf("Invalid Customer id!\n");
        return;
    }

    for (int i = 0; i < customer_count; i++)
    {
        if (customer_id == c[i].id)
        {
            int user_event_id;
            while (1)
            {
                printf("\nEvent Event ID: ");
                if (scanf("%d", &user_event_id) != 1)
                {
                    while(getchar() != '\n');
                    continue;
                }
                break;
            }
            if (event_count == 0)
            {
                printf("No event found!\n");
            }
            else if (user_event_id <= 0 || user_event_id > event_count)
            {
                printf("Invalid event id!\n");
            }

            else
            {
                for (int j = 0; j < event_count; j++)
                {
                    if (user_event_id == e[j].id)
                    {
                        // while (1)
                        // {
                        //     printf("Enter Customer ID: ");
                        //     if (scanf("%d", &t[ticket_count].customer_id) != 1)
                        //     {
                        //         while(getchar() != '\n');
                        //         continue;
                        //     }
                        //     break;
                        // }
                        t[ticket_count].price = 1000;
                        printf("\nTicket Price for this event is %d\n", t[ticket_count].price);
                        while (1)
                        {
                            char user_input;
                            getchar();
                            printf("Enter y to book a ticket or n to go back to ticket menu: ");
                            scanf("%c", &user_input);
                            if (user_input == 'y' || user_input == 'Y')
                            {
                                t[ticket_count].seat_no = ticket_count + 1;
                                t[ticket_count].id = ticket_count + 1;
                                t[ticket_count].customer_id = customer_id;
                                t[ticket_count].event_id = user_event_id;
                                printf("----------------------------------------\n");
                                printf("\033[93mYou have successfully book a ticket...\033[0m\n");
                                printf("\033[93mTicket id is %d\033[0m\n", t[ticket_count].id);
                                printf("\033[93mSeat no is %d\033[0m\n", t[ticket_count].seat_no);
                                printf("----------------------------------------\n");
                                FILE* ticket_file = fopen("ticket.txt", "a");
                                fprintf(ticket_file, "%d|%d|%d|%d|%d\n", t[ticket_count].id, t[ticket_count].event_id, t[ticket_count].customer_id, t[ticket_count].seat_no, t[ticket_count].price);
                                fclose(ticket_file);
                                ticket_count ++;
                                return;
                            }
                            else if(user_input == 'n' || user_input == 'N')
                            {
                                return;
                            }
                        }
                    }
                }
            }
        }    
    }
}    

void search_ticket()
{
    if (ticket_count == 0)
    {
        printf("No ticket booked yet!\n\n");
        return;
    }

    int ticket_id_user;
    while(1)
    {
        printf("Enter Ticket id: ");
        if (scanf("%d", &ticket_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (ticket_id_user <= 0 || ticket_id_user > ticket_count)
    {
        printf("No ticket found!\n");
    }
    else
    {
        for (int i = 0; i < ticket_count; i ++)
        {
            if (t[i].id == ticket_id_user)
            {
                printf("--------------------------------\n");
                printf("Ticket ID: %d\n", t[i].id);
                printf("Event ID: %d\n", t[i].event_id);
                printf("Customer ID: %d\n", t[i].customer_id);
                printf("Seat no: %d\n", t[i].seat_no);
                printf("--------------------------------\n\n");
                return;
            }
        }
    }
}

void list_tickets()
{
    if (ticket_count == 0)
    {
        printf("No ticket booked yet!");
        return;
    }
    printf("\n\n");
    printf("%-15s %-25s %-15s %-25s %-10s\n", "Ticket ID", "Event ID", "Customer ID", "Seat no", "Price");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int s = 0; s < ticket_count; s++)
    {
        printf("%-15d %-25d %-15d %-25d %-10d\n", t[s].id, t[s].event_id, t[s].customer_id, t[s].seat_no, t[s].price);
    }
    printf("\n\n");
}

void cancel_ticket()
{
    if (ticket_count == 0)
    {
        printf("No ticket booked yet!\n");
        return;
    }

    int ticket_id_user;

    while(1)
    {
        printf("Enter Ticket ID: ");
        if (scanf("%d", &ticket_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (ticket_id_user <= 0 || ticket_id_user > ticket_count)
    {
        printf("No Ticket found!\n");
    }
    else
    {
        for (int i = 0; i < ticket_count; i++)
        {
            if (ticket_id_user  == t[i].id)
            {
                for (int j = i; j < ticket_count - 1; j++)
                {
                    t[j] = t[j + 1];
                    t[j].id = j + 1;
                }
                ticket_count--;
                update_tickets();
                printf("Ticket has been cancelled successfully...\n\n");
                return;
            }
        }
    }
}

void load_tickets()
{
    FILE* ticket_file = fopen("ticket.txt","r");
    if (ticket_file == NULL)
    {
        return;
    }
    while (fscanf(ticket_file, "%d|%d|%d|%d|%d", &t[ticket_count].id, &t[ticket_count].event_id, &t[ticket_count].customer_id, &t[ticket_count].seat_no, &t[ticket_count].price) != EOF)
    {
        ticket_count++;
    }
    fclose(ticket_file);
}

void update_tickets()
{
    FILE *ticket_file = fopen("ticket.txt", "w");

    for (int i = 0; i < ticket_count; i++)
    {
        fprintf(ticket_file, "%d|%d|%d|%d|%d\n", t[ticket_count].id, t[ticket_count].event_id, t[ticket_count].customer_id, t[ticket_count].seat_no, t[ticket_count].price);
    }     
    fclose(ticket_file);
}

// Organizer Menu Functions

void organizer_menu_screen()          
{
    printf("\n\033[34m>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n");
    printf("\033[34m***    Organizer Menu    ***\033[0m\n");
    printf("\033[34m>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n");

    printf("---------------------\n");
    printf("1. Add Organizer\n");
    printf("2. List Organizers\n");
    printf("3. Search Organizer\n");
    printf("4. Update Organizer\n");
    printf("5. Delete Organizer\n");
    printf("6. Back to main menu\n");
    printf("---------------------\n\n");
}

void organizer_menu()
{
    while (1)
    {
        organizer_menu_screen();
        int choice;
        printf("\033[32mEnter your choice : \033[0m");
        choice = get_int();

        if (choice == -1)
        {
            printf("Press enter to go back to organizer menu: ");
            getchar();
            printf("\n");
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                add_organizer();
                break;
            }
            case 2:
            {
                list_organizers();
                break;
            }
            case 3:
            {
                search_organizer();
                break;
            }
            case 4:
            {
                update_organizer();
                break;
            }
            case 5:
            {
                delete_organizer();
                break;
            }
            case 6:
            {
                printf("\n");              
                return;
            }
            default:
            {
                printf("Invalid choice...\n\n");
            }
        }
        printf("Press enter to go back to organizer menu: ");
        getchar();
        getchar();
        printf("\n\n");
    }    
}

void add_organizer()
{
    printf("Organizer Name: ");
    scanf(" %29[^\n]", o[organizer_count].name);
    printf("Organizer Phone: ");
    scanf(" %14[^\n]", o[organizer_count].phone);
    printf("Organizer Company: ");
    scanf(" %29[^\n]", o[organizer_count].company);

    o[organizer_count].id = organizer_count + 1;
    printf("----------------------------------------\n");
    printf("\033[93mYou have successfully add an organizer...\033[0m\n");
    printf("\033[93mOrganizer id is %d\033[0m\n", o[organizer_count].id);
    printf("----------------------------------------\n");
    FILE* organizer_file = fopen("organizer.txt", "a");
    fprintf(organizer_file, "%d|%s|%s|%s\n", o[organizer_count].id, o[organizer_count].name, o[organizer_count].phone, o[organizer_count].company);
    fclose(organizer_file);
    organizer_count ++;
}

void search_organizer()
{
    if (organizer_count == 0)
    {
        printf("No organizer found!\n\n");
        return;
    }

    int organizer_id_user;
    while(1)
    {
        printf("Enter Organizer id: ");
        if (scanf("%d", & organizer_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (organizer_id_user <= 0 || organizer_id_user > organizer_count)
    {
        printf("No organizer found!\n");
    }
    else
    {
        for (int i = 0; i < organizer_count; i ++)
        {
            if (o[i].id == organizer_id_user)
            {
                printf("--------------------------------\n");
                printf("Organizer ID: %d\n", o[i].id);
                printf("Organizer Name: %s\n", o[i].name);
                printf("Organizer Phone: %s\n", o[i].phone);
                printf("Organizer Company: %s\n", o[i].company);
                printf("--------------------------------\n\n");
                return;
            }
        }
    }
}

void list_organizers()
{
    if (organizer_count == 0)
    {
        printf("No organizer added yet!\n");
        return;
    }
    printf("\n\n");
    printf("%-15s %-25s %-15s %-25s\n", "Organizer ID", "Name", "Phone", "Company");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int s = 0; s < organizer_count; s++)
    {
        printf("%-15d %-25s %-15s %-25s\n", o[s].id, o[s].name, o[s].phone, o[s].company);
    }
    printf("\n\n");
}

void update_organizer()
{
    if (organizer_count == 0)
    {
        printf("No organizer found!\n");
        return;
    }

    int organizer_id_user;

    while(1)
    {
        printf("Enter Organizer ID: ");
        if (scanf("%d", &organizer_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if (organizer_id_user <= 0 || organizer_id_user > organizer_count)
    {
        printf("No organizer found!\n");
    }
    else
    {
        for (int i = 0; i < organizer_count; i ++)
        {
            if (o[i].id == organizer_id_user)
            {
                printf("--------------------------------\n");
                printf("Organizer ID: %d\n", o[i].id);
                printf("Organizer Name: %s\n", o[i].name);
                printf("Organizer Phone: %s\n", o[i].phone);
                printf("Organizer Email: %s\n", o[i].company);
                printf("--------------------------------\n\n");

                printf("Organizer Name: ");
                scanf(" %29[^\n]", o[i].name);
                printf("Organizer Phone: ");
                scanf(" %14[^\n]", o[i].phone);
                printf("Organizer Company: ");
                scanf(" %29[^\n]", o[i].company);
                update_organizers();
                printf("Organizer has been updated successfully!\n\n");
                return;
            }
        }
    }
}

void delete_organizer()
{
    if (organizer_count == 0)
    {
        printf("No organizer found!\n");
        return;
    }

    int organizer_id_user;

    while(1)
    {
        printf("Enter Organizer ID: ");
        if (scanf("%d", &organizer_id_user) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    if ( organizer_id_user <= 0 || organizer_id_user > organizer_count)
    {
        printf("No organizer found!\n");
    }
    else
    {
        for (int i = 0; i < organizer_count; i++)
        {
            if (organizer_id_user  == o[i].id)
            {
                for (int j = i; j < organizer_count - 1; j++)
                {
                    o[j] = o[j + 1];
                    o[j].id = j + 1;
                }
                organizer_count--;
                update_organizers();
                printf("Organizer has been deleted successfully...\n\n");
                return;
            }
        }
    }
}

void load_organizers()
{
    FILE* organizer_file = fopen("organizer.txt","r");
    if (organizer_file == NULL)
    {
        return;
    }
    while (fscanf(organizer_file, "%d|%[^|]|%[^|]|%[^|]", &o[organizer_count].id, o[organizer_count].name, o[organizer_count].phone, o[organizer_count].company) != EOF)
    {
        organizer_count++;
    }
    fclose(organizer_file);
}

void update_organizers()
{
    FILE *organizer_file = fopen("organizer.txt", "w");

    for (int i = 0; i < organizer_count; i++)
    {
        fprintf(organizer_file, "%d|%s|%s|%s\n", o[organizer_count].id, o[organizer_count].name, o[organizer_count].phone, o[organizer_count].company);
    }     
    fclose(organizer_file);
}
