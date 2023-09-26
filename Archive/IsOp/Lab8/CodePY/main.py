def DLP(c, A, b):
    n = A.shape[1]
    A_ext = np.hstack([A, -A, np.eye(n)])
    b_ext = b
    c_ext = np.hstack([c, -c, np.zeros(n)])
    x = np.zeros(2*n)
    x[:n] = np.ones(n)
    while True:
    k = np.argmax(c_ext.dot(A_ext) < 0)
    if c_ext.dot(A_ext)[:, k].max() >= 0:
        break
    ratios = np.where(A_ext[:, k] > 0, b_ext / A_ext[:, k], np.inf)
    l = np.argmin(ratios)
    if np.isinf(ratios[l]):
        return None
    x = np.zeros(2*n)
    x[l] = x[l+n] = ratios[l]
    B = {l, l+n}
    while True:
        k = np.argmax(c_ext[B].dot(A_ext) < 0)
        if c_ext[B].dot(A_ext)[:, k].max() >= 0:
            break
        ratios = np.where(A_ext[:, k] > 0, b_ext / A_ext[:, k], np.inf)
        l = np.argmin(ratios)
        if np.isinf(ratios[l]):
            return None
        x[B] = 0
        x[l] = x[l+n] = ratios[l]
        B.discard(B.intersection({l, l+n}).pop())
        B.add(k)
    return x[:n]