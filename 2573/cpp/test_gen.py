
if __name__ == "__main__":
    k = 1000
    res = []
    for i in range(k):
        res.append([min(k-i, k-j) for j in range(k)])

    print(res)