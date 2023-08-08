def print_N_M(N, M):
    for n in range(1, N+1):
        row_list = []
        for m in range(1, M+1):
            row_list.append(str(m + (n-1) * M))
            
        print(" ".join(row_list))
    
    
if __name__ == "__main__":
    N, M = map(int, input().split())
    
    print_N_M(N=N, M=M)