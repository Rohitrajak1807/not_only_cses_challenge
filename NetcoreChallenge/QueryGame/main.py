def query_game(arr_len, arr, q_len, queries):
    idx_to_el = {i: arr[i] for i in range(len(arr))}
    el_to_idx = {v: k for k, v in idx_to_el.items()}
    is_reversed = False
    for query in queries:
        if query[0] == 1:
            is_reversed = not is_reversed
        elif query[0] == 2:
            i = query[1] - 1
            j = query[2] - 1
            if is_reversed:
                i = arr_len - 1 - i
                j = arr_len - 1 - j
            el_1 = idx_to_el[i]
            el_2 = idx_to_el[j]
            idx_to_el[i], idx_to_el[j] = idx_to_el[j], idx_to_el[i]
            el_to_idx[el_1] = j
            el_to_idx[el_2] = i
        elif query[0] == 3:
            elem = query[1]
            idx = el_to_idx[elem]
            if is_reversed:
                idx = arr_len - idx - 1
            print(idx + 1)


if __name__ == '__main__':
    query_game(1, [1, 2, 3, 4], 3, [[2, 2, 4],
                                    [3, 2, 0],
                                    [1, 0, 0],
                                    [3, 1, 0]
                                    ])
