import matplotlib.pyplot as plt

def graph_data(insert_data, look_up_data, delete_data, load_factor_data, save_location):
    plt.plot(load_factor_data, insert_data, label="Insert")
    plt.plot(load_factor_data, look_up_data, label="Look Up")
    plt.plot(load_factor_data, delete_data, label="Delete")
    plt.xlabel("Load Factor")
    plt.ylabel("Run Time")
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
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-One-A")

    # LL Chaining - Hash function one - Data Set C
    insert_data = [0.000016, 0.000012, 0.000014, 0.000015, 0.000017, 0.000016]
    look_up_data = [0.000002, 0.000003, 0.000004, 0.000005, 0.000006, 0.000004]
    delete_data = [0.000007, 0.000004, 0.000006, 0.000007, 0.000007, 0.000009]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-One-C")

    # LL Chaining - Hash function two - Data Set A
    insert_data = [0.000022, 0.000018, 0.000016, 0.000016, 0.000019, 0.000017]
    look_up_data = [0.000003, 0.000005, 0.000004, 0.000006, 0.000006, 0.000007]
    delete_data = [0.000008, 0.000009, 0.000008, 0.000008, 0.000009, 0.000009]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Two-A")

    # LL Chaining - Hash function two - Data Set C
    insert_data = [0.000023, 0.000019, 0.000022, 0.000019, 0.000023, 0.000020]
    look_up_data = [0.000006, 0.000006, 0.000008, 0.000007, 0.000009, 0.000009]
    delete_data = [0.000008, 0.000010, 0.000013, 0.000011, 0.000011, 0.000011]
    load_factor_data = [0.1, 0.2, 0.5, 0.7, 0.9, 1.0]
    graph_data(insert_data, look_up_data, delete_data, load_factor_data, "./LL_Chaining_Graphs/LLChaining-Two-C")


if __name__ == "__main__":
    main()