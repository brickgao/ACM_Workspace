while True:
    dp = [[0 for x in range(2)] for y in range(1000)]
    r = int(raw_input())
    if r < 0:
        break
    if r == 0:
        print "1"
        continue
    s = ""
    tmp = r
    while(tmp > 0):
        if tmp & 1 == 1:
            s += '1'
        else:
            s += '0'
        tmp >>= 1
    length = len(s)
    bef = -1
    for i in range(0, length):
        if s[i] == '1':
            if bef == -1:
                dp[i][0] = 1
                dp[i][1] = i - bef - 1
                bef = i
            else:
                dp[i][0] = dp[bef][0] + dp[bef][1]
                dp[i][1] = (i - bef - 1) * dp[bef][0] + (i - bef) * dp[bef][1]
                bef = i
    print dp[length - 1][0] + dp[length - 1][1]
