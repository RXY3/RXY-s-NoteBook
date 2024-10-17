
def longestCommonPrefix(strs):
    if len(strs) == 0:
        return ""
    m = len(strs)
    min = 100000
    minstr = ""
    for i in range(0, m):
        if strs[i] == "":
            return ""
        if len(strs[i]) < min:
            minstr = strs[i]
            min = len(strs[i])
    n = len(minstr)
    print(n)
    for i in range(0, n):
        for j in range(0, m):
            if minstr[i] != strs[j][i]:
                return minstr[0:i]
    return minstr
    

print(longestCommonPrefix(["cir","car"]))
    

