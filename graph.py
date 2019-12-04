import matplotlib.pyplot as plt

def graph_data(insert_data, look_up_data, delete_data, load_factor_data, save_location, hash_function, data_set, collision_method):
    hash_choice = ""
    data_selection = ""
    collision_choice = ""
    if hash_function == 1:
        hash_choice = "Hash Function One"
    else:
        hash_choice = "Hash Function Two"
    if data_set == 1:
        data_selection = "Data Set A"
    else:
        data_selection = "Data Set C"
    if collision_method == 1:
        collision_choice = "LL Chaining"
    elif collision_method == 2:
        collision_choice = "BST Chaining"
    elif collision_method == 3:
        collision_choice = "Linear Probing"
    else:
        collision_choice = "Cuckoo Hashing"
    plt.plot(load_factor_data, insert_data, label="Insert")
    plt.plot(load_factor_data, look_up_data, label="Look Up")
    plt.plot(load_factor_data, delete_data, label="Delete")
    plt.xlabel("Load Factor")
    plt.ylabel("Run Time")
    if collision_method == 4:
        plt.title(collision_choice + " - " + data_selection)
    else:
        plt.title(collision_choice + " - " + hash_choice + " - " + data_selection)
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.00), shadow=True, ncol=2)
    #plt.show()
    plt.savefig(save_location)
    plt.close()

def main():
    # LL Chaining - Hash function one - Data Set A
    insert_data = [0.000016, 0.000013, 0.000014, 0.000015, 0.000019, 0.000015]
    look_up_data = [0.000003, 0.000003, 0.000004, 0.000004, 0.000006, 0.000004]
    delete_data = [0.000005, 0.000005, 0.000006, 0.000007, 0.000008, 0.000007]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-One-A", 1, 1, 1)

    # LL Chaining - Hash function one - Data Set C
    insert_data = [0.000016, 0.000012, 0.000014, 0.000015, 0.000017, 0.000016]
    look_up_data = [0.000002, 0.000003, 0.000004, 0.000005, 0.000006, 0.000004]
    delete_data = [0.000007, 0.000004, 0.000006, 0.000007, 0.000007, 0.000009]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-One-C", 1, 2, 1)

    # LL Chaining - Hash function two - Data Set A
    insert_data = [0.000022, 0.000018, 0.000016, 0.000016, 0.000019, 0.000017]
    look_up_data = [0.000003, 0.000005, 0.000004, 0.000006, 0.000006, 0.000007]
    delete_data = [0.000008, 0.000009, 0.000008, 0.000008, 0.000009, 0.000009]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Two-A", 2, 1, 1)

    # LL Chaining - Hash function two - Data Set C
    insert_data = [0.000023, 0.000019, 0.000022, 0.000019, 0.000023, 0.000020]
    look_up_data = [0.000006, 0.000006, 0.000008, 0.000007, 0.000009, 0.000009]
    delete_data = [0.000008, 0.000010, 0.000013, 0.000011, 0.000011, 0.000011]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Two-C", 2, 2, 1)

    # BST Chaining - Hash function one - Data Set A
    insert_data = [0.000020, 0.000019, 0.000018, 0.000020, 0.000022, 0.000020]
    look_up_data = [0.000003, 0.000004, 0.000004, 0.000004, 0.000006, 0.000006]
    delete_data = [0.000020, 0.000019, 0.000015, 0.000017, 0.000017, 0.000016]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-One-A", 1, 1, 2)

    # BST Chaining - Hash function one - Data Set C
    insert_data = [0.000020, 0.000018, 0.000024, 0.000022, 0.000024, 0.000022]
    look_up_data = [0.000004, 0.000003, 0.000005, 0.000006, 0.000006, 0.000008]
    delete_data = [0.000029, 0.000019, 0.000019, 0.000017, 0.000016, 0.000018]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-One-C", 1, 2, 2)

    # BST Chaining - Hash function two - Data Set A
    insert_data = [0.000020, 0.000021, 0.000019, 0.000021, 0.000030, 0.000023]
    look_up_data = [0.000004, 0.000006, 0.000005, 0.000006, 0.000007, 0.000008]
    delete_data = [0.000020, 0.000021, 0.000017, 0.000018, 0.000018, 0.000017]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-Two-A", 2, 1, 2)

    # BST Chaining - Hash function two - Data Set C
    insert_data = [0.000022, 0.000024, 0.000023, 0.000025, 0.000027, 0.000028]
    look_up_data = [0.000005, 0.000006, 0.000007, 0.000010, 0.000010, 0.000009]
    delete_data = [0.000022, 0.000023, 0.000020, 0.000020, 0.000022, 0.000019]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-Two-C", 2, 2, 2)

    # Linear Probing - Hash function one - Data Set A
    insert_data = [0.000004, 0.000004, 0.000006, 0.000007, 0.000016, 0.002467]
    look_up_data = [0.000004, 0.000002, 0.000004, 0.000008, 0.000020, 0.001476]
    delete_data = [0.000003, 0.000004, 0.000006, 0.000007, 0.000020, 0.001482]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LP_Chaining_Graphs/LPChaining-One-A", 1, 1, 3)

    # Linear Probing - Hash function one - Data Set C
    insert_data = [0.000005, 0.000005, 0.000007, 0.000008, 0.000024, 0.002591]
    look_up_data = [0.000003, 0.000004, 0.000006, 0.000008, 0.000028, 0.001466]
    delete_data = [0.000003, 0.000003, 0.000007, 0.000010, 0.000030, 0.001396]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LP_Chaining_Graphs/LPChaining-One-C", 1, 2, 3)

    # Linear Probing - Hash function two - Data Set A
    insert_data = [0.000005, 0.000005, 0.000009, 0.000009, 0.000027, 0.002506]
    look_up_data = [0.000004, 0.000005, 0.000008, 0.000009, 0.000032, 0.001500]
    delete_data = [0.000004, 0.000004, 0.000010, 0.000010, 0.000034, 0.001504]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LP_Chaining_Graphs/LPChaining-Two-A", 2, 1, 3)

    # Linear Probing - Hash function two - Data Set C
    insert_data = [0.000005, 0.000006, 0.000291, 0.000416, 0.000617, 0.001987]
    look_up_data = [0.000004, 0.000006, 0.000307, 0.000555, 0.000824, 0.001288]
    delete_data = [0.000005, 0.000008, 0.000306, 0.000555, 0.000821, 0.001286]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LP_Chaining_Graphs/LPChaining-Two-C", 2, 2, 3)

    # Cuckoo Hashing - Hash function one - Data Set A
    insert_data = [0.000006, 0.000005, 0.000005, 0.000007, 0.000005, 0.000007]
    look_up_data = [0.000002, 0.000002, 0.000002, 0.000013, 0.000001, 0.000002]
    delete_data = [0.000002, 0.000002, 0.000002, 0.000006, 0.000001, 0.000002]
    load_factor_data = [0.1, 0.2, 0.3, 0.4, 0.5, .7]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./CH_Chaining_Graphs/CHChaining-A", 1, 1, 4)

    # Cuckoo Hashing - Hash function one - Data Set C
    insert_data = [0.000007, 0.000003, 0.000004, 0.000005, 0.000006, 0.000015]
    look_up_data = [0.000001, 0.000001, 0.000001, 0.000010, 0.000001, 0.000001]
    delete_data = [0.000002, 0.000002, 0.000007, 0.000003, 0.000005, 0.000014]
    load_factor_data = [0.1, 0.2, 0.3, 0.4, 0.5, .7]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./CH_Chaining_Graphs/CHChaining-C", 1, 2, 4)




if __name__ == "__main__":
    main()