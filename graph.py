import matplotlib.pyplot as plt
import csv

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

def graph_average(insert_average, look_up_average, delete_average, load_factor_data, save_location, collision_method):
    if collision_method == 1:
        collision_choice = "LL Chaining"
    elif collision_method == 2:
        collision_choice = "BST Chaining"
    elif collision_method == 3:
        collision_choice = "Linear Probing"
    else:
        collision_choice = "Cuckoo Hashing"
    plt.plot(load_factor_data, insert_average, label="Insert Average")
    plt.plot(load_factor_data, look_up_average, label="Look Up Average")
    plt.plot(load_factor_data, delete_average, label="Delete Average")
    plt.xlabel("Load Factor")
    plt.ylabel("Run Time Average")
    plt.title(collision_choice + " Averages")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.00), shadow=True, ncol=2)
    plt.savefig(save_location)
    plt.close()

def graph_index_vs_value(file_name, collision_method):
    values = []
    indexes = []
    file = open(file_name, "r")
    i = 0
    for line in file:
        values.append(int(line))
        indexes.append(i)
        i += 1
    plt.bar(indexes, values)
    plt.xlabel("Indexes")
    plt.ylabel("Value count")
    if collision_method == 1 :
        plt.savefig("LL Index vs Values")
        plt.title("LL Index vs Values")
    elif collision_method == 2:
        plt.savefig("BST Index vs Values")
        plt.title("BST Index vs Values")
    plt.close()

def main():
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    # LL Chaining - Hash function one - Data Set A
    insert_data_one = [0.000016, 0.000013, 0.000014, 0.000015, 0.000019, 0.000015]
    look_up_data_one = [0.000003, 0.000003, 0.000004, 0.000004, 0.000006, 0.000004]
    delete_data_one = [0.000005, 0.000005, 0.000006, 0.000007, 0.000008, 0.000007]
    graph_data(insert_data_one, look_up_data_one, delete_data_one, load_factor_data, "./LL_Chaining_Graphs/LLChaining-One-A", 1, 1, 1)

    # LL Chaining - Hash function one - Data Set C
    insert_data_two = [0.000016, 0.000012, 0.000014, 0.000015, 0.000017, 0.000016]
    look_up_data_two = [0.000002, 0.000003, 0.000004, 0.000005, 0.000006, 0.000004]
    delete_data_two = [0.000007, 0.000004, 0.000006, 0.000007, 0.000007, 0.000009]
    graph_data(insert_data_two, look_up_data_two, delete_data_two, load_factor_data, "./LL_Chaining_Graphs/LLChaining-One-C", 1, 2, 1)

    # LL Chaining - Hash function two - Data Set A
    insert_data_three = [0.000022, 0.000018, 0.000016, 0.000016, 0.000019, 0.000017]
    look_up_data_three = [0.000003, 0.000005, 0.000004, 0.000006, 0.000006, 0.000007]
    delete_data_three = [0.000008, 0.000009, 0.000008, 0.000008, 0.000009, 0.000009]
    graph_data(insert_data_three, look_up_data_three, delete_data_three, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Two-A", 2, 1, 1)

    # LL Chaining - Hash function two - Data Set C
    insert_data_four = [0.000023, 0.000019, 0.000022, 0.000019, 0.000023, 0.000020]
    look_up_data_four = [0.000006, 0.000006, 0.000008, 0.000007, 0.000009, 0.000009]
    delete_data_four = [0.000008, 0.000010, 0.000013, 0.000011, 0.000011, 0.000011]
    graph_data(insert_data_four, look_up_data_four, delete_data_four, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Two-C", 2, 2, 1)

    # LL Chaining - Averages
    insert_ave = []
    look_up_ave = []
    delete_ave = []
    for i in range(len(load_factor_data)):
        insert_ave.append((insert_data_one[i] + insert_data_two[i] + insert_data_three[i] + insert_data_four[i])/4.0)
    for i in range(len(load_factor_data)):
        look_up_ave.append((look_up_data_one[i] + look_up_data_two[i] + look_up_data_three[i] + look_up_data_three[i] + look_up_data_four[i])/4.0)
    for i in range(len(load_factor_data)):
        delete_ave.append((delete_data_one[i] + delete_data_two[i] + delete_data_three[i] + delete_data_four[i])/4.0)
    graph_average(insert_ave, look_up_ave, delete_ave, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Averages", 1)

    # -------------------------------------------------------------------------------------------------------------------------------- #

    # BST Chaining - Hash function one - Data Set A
    insert_data_one = [0.000020, 0.000019, 0.000018, 0.000020, 0.000022, 0.000020]
    look_up_data_one = [0.000003, 0.000004, 0.000004, 0.000004, 0.000006, 0.000006]
    delete_data_one = [0.000020, 0.000019, 0.000015, 0.000017, 0.000017, 0.000016]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_one, look_up_data_one, delete_data_one, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-One-A", 1, 1, 2)

    # BST Chaining - Hash function one - Data Set C
    insert_data_two = [0.000020, 0.000018, 0.000024, 0.000022, 0.000024, 0.000022]
    look_up_data_two = [0.000004, 0.000003, 0.000005, 0.000006, 0.000006, 0.000008]
    delete_data_two = [0.000029, 0.000019, 0.000019, 0.000017, 0.000016, 0.000018]
    load_factor_data_two = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_two, look_up_data_two, delete_data_two, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-One-C", 1, 2, 2)

    # BST Chaining - Hash function two - Data Set A
    insert_data_three = [0.000020, 0.000021, 0.000019, 0.000021, 0.000030, 0.000023]
    look_up_data_three = [0.000004, 0.000006, 0.000005, 0.000006, 0.000007, 0.000008]
    delete_data_three = [0.000020, 0.000021, 0.000017, 0.000018, 0.000018, 0.000017]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_three, look_up_data_three, delete_data_three, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-Two-A", 2, 1, 2)

    # BST Chaining - Hash function two - Data Set C
    insert_data_four = [0.000022, 0.000024, 0.000023, 0.000025, 0.000027, 0.000028]
    look_up_data_four = [0.000005, 0.000006, 0.000007, 0.000010, 0.000010, 0.000009]
    delete_data_four = [0.000022, 0.000023, 0.000020, 0.000020, 0.000022, 0.000019]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_four, look_up_data_four, delete_data_four, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-Two-C", 2, 2, 2)

    # BST Chaining - Averages
    insert_ave = []
    look_up_ave = []
    delete_ave = []
    for i in range(len(load_factor_data)):
        insert_ave.append((insert_data_one[i] + insert_data_two[i] + insert_data_three[i] + insert_data_four[i]) / 4.0)
    for i in range(len(load_factor_data)):
        look_up_ave.append((look_up_data_one[i] + look_up_data_two[i] + look_up_data_three[i] + look_up_data_three[i] +
                            look_up_data_four[i]) / 4.0)
    for i in range(len(load_factor_data)):
        delete_ave.append((delete_data_one[i] + delete_data_two[i] + delete_data_three[i] + delete_data_four[i]) / 4.0)
    graph_average(insert_ave, look_up_ave, delete_ave, load_factor_data, "./BST_Chaining_Graphs/BSTChaining-Averages", 2)

    #-------------------------------------------------------------------------------------------------------------------------------- #

    # Linear Probing - Hash function one - Data Set A
    insert_data_one = [0.000004, 0.000004, 0.000006, 0.000007, 0.000016, 0.002467]
    look_up_data_one = [0.000004, 0.000002, 0.000004, 0.000008, 0.000020, 0.001476]
    delete_data_one = [0.000003, 0.000004, 0.000006, 0.000007, 0.000020, 0.001482]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_one, look_up_data_one, delete_data_one, load_factor_data, "./Linear_Probing_Graphs/Linear-Probing-One-A", 1, 1, 3)

    # Linear Probing - Hash function one - Data Set C
    insert_data_two = [0.000005, 0.000005, 0.000007, 0.000008, 0.000024, 0.002591]
    look_up_data_two = [0.000003, 0.000004, 0.000006, 0.000008, 0.000028, 0.001466]
    delete_data_two = [0.000003, 0.000003, 0.000007, 0.000010, 0.000030, 0.001396]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_two, look_up_data_two, delete_data_two, load_factor_data, "./Linear_Probing_Graphs/Linear-Probing-One-C", 1, 2, 3)

    # Linear Probing - Hash function two - Data Set A
    insert_data_three = [0.000005, 0.000005, 0.000009, 0.000009, 0.000027, 0.002506]
    look_up_data_three = [0.000004, 0.000005, 0.000008, 0.000009, 0.000032, 0.001500]
    delete_data_three = [0.000004, 0.000004, 0.000010, 0.000010, 0.000034, 0.001504]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_three, look_up_data_three, delete_data_three, load_factor_data, "./Linear_Probing_Graphs/Linear-Probing-Two-A", 2, 1, 3)

    # Linear Probing - Hash function two - Data Set C
    insert_data_four = [0.000005, 0.000006, 0.000291, 0.000416, 0.000617, 0.001987]
    look_up_data_four = [0.000004, 0.000006, 0.000307, 0.000555, 0.000824, 0.001288]
    delete_data_four = [0.000005, 0.000008, 0.000306, 0.000555, 0.000821, 0.001286]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data_four, look_up_data_four, delete_data_four, load_factor_data, "./Linear_Probing_Graphs/Linear-Probing-Two-C", 2, 2, 3)

    # Linear Probing - Averages
    insert_ave = []
    look_up_ave = []
    delete_ave = []
    for i in range(len(load_factor_data)):
        insert_ave.append((insert_data_one[i] + insert_data_two[i] + insert_data_three[i] + insert_data_four[i]) / 4.0)
    for i in range(len(load_factor_data)):
        look_up_ave.append((look_up_data_one[i] + look_up_data_two[i] + look_up_data_three[i] + look_up_data_three[i] +
                            look_up_data_four[i]) / 4.0)
    for i in range(len(load_factor_data)):
        delete_ave.append((delete_data_one[i] + delete_data_two[i] + delete_data_three[i] + delete_data_four[i]) / 4.0)
    graph_average(insert_ave, look_up_ave, delete_ave, load_factor_data, "./Linear_Probing_Graphs/Linear-Probing-Averages", 3)

    # -------------------------------------------------------------------------------------------------------------------------------- #

    # Cuckoo Hashing - Hash function one - Data Set A
    insert_data_one = [0.000006, 0.000005, 0.000005, 0.000007, 0.000005, 0.000007]
    look_up_data_one = [0.000002, 0.000002, 0.000002, 0.000013, 0.000001, 0.000002]
    delete_data_one = [0.000002, 0.000002, 0.000002, 0.000006, 0.000001, 0.000002]
    load_factor_data = [0.1, 0.2, 0.3, 0.4, 0.5, .7]
    graph_data(insert_data_one, look_up_data_one, delete_data_one, load_factor_data, "./Cuckoo_Hashing_Graphs/Cuckoo-Hashing-A", 1, 1, 4)

    # Cuckoo Hashing - Hash function one - Data Set C
    insert_data_two = [0.000007, 0.000003, 0.000004, 0.000005, 0.000006, 0.000015]
    look_up_data_two = [0.000001, 0.000001, 0.000001, 0.000010, 0.000001, 0.000001]
    delete_data_two = [0.000002, 0.000002, 0.000007, 0.000003, 0.000005, 0.000014]
    load_factor_data = [0.1, 0.2, 0.3, 0.4, 0.5, .7]
    graph_data(insert_data_two, look_up_data_two, delete_data_two, load_factor_data, "./Cuckoo_Hashing_Graphs/Cuckoo-Hashing-C", 1, 2, 4)

    # Cuckoo Hashing - Averages
    insert_ave = []
    look_up_ave = []
    delete_ave = []
    for i in range(len(load_factor_data)):
        insert_ave.append((insert_data_one[i] + insert_data_two[i]) / 2.0)
    for i in range(len(load_factor_data)):
        look_up_ave.append((look_up_data_one[i] + look_up_data_two[i]) / 2.0)
    for i in range(len(load_factor_data)):
        delete_ave.append((delete_data_one[i] + delete_data_two[i]) / 2.0)
    graph_average(insert_ave, look_up_ave, delete_ave, load_factor_data, "./Cuckoo_Hashing_Graphs/Cuckoo-Hashing-Averages", 4)

    # -------------------------------------------------------------------------------------------------------------------------------- #

    # Graph data sets
    graph_index_vs_value("LLdataFile.txt", 1)
    graph_index_vs_value("BSTdataFile.txt", 2)


if __name__ == "__main__":
    main()