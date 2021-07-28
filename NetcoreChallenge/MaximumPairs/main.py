def max_pairs(length, numbers):
    numbers.sort(key=lambda x: lowest_set(x))
    total = 0
    last_idx = len(numbers) - 1
    while last_idx >= 1:
        bwise_or = numbers[last_idx] | numbers[last_idx - 1]
        total += 1 << lowest_set(bwise_or)
        last_idx -= 2
    return total


def lowest_set(binary):
    low = (binary & -binary)
    low_bit = -1
    while low:
        low >>= 1
        low_bit += 1

    return low_bit


def main():
    print(max_pairs(6, [9, 4, 10, 4, 5, 7]))


if __name__ == '__main__':
    main()
