import fs from 'fs';

const root = '../';

// oj平台上已提交题目的列表
const finishedProblemStr = `1000 1001 1002 1003 1004 1005 1007 1008 1009 1048 1051 1055 1056 1057 1058 1059 1060 1061 1062 1063 1064 1065 1066 1067 1068 1069 1070 1071 1073 1074 1075 1076 1077 1078 1079 1088 1089 1090 1093 1094 1095 1096 1097 1098 1170 1171 1172 1173 1174 1175 1176 1177 1178 1179 1180 1181 1182 1183 1184 1185 1187 1188 1189 1192 1199 1225 1226 1227 1229 1230 1313 1397 1398 1419 1420 1421 1422 1423 1424 1425 1426 1427 1428 1429 1431 1432 1433 1435 1469 1470 1471 1472 1473 1474 1475 1476 1477 1478 1479 1480 1481 1482 1483 1485 1486 1487 1488 1489 1490 1491 1492 1493 1494 1495 1496 1497 1498 1499 1500 1501 1502 1503 1504 1505 1506 1507 1508 1509 1510 1511 1512 1513 1514 1515 1516 1517 1518 1519 1520 1721 1722 1723 1724 1725 1727 1728 1729 1730 1731 1734 1736 1737 1738 1740 1741 1742 1743 1744 1745 1746 1747 1748 1749 1754 1756 1757 1758 1760 1761 1764 1768 1769 1770 1771 1772 1774 1776 1800 1801 1802 1803 1805 1806 1807 1808 1809 1811 1812 1813 1814 1815 1816 1817 1819 1821 1822 1825 1828 1829 1837 1845 1846 1848 1849 1850 1851 1852 1853 1854 1855 1856 1857 1858 1859 1860 1861 1862 1863 1869 1870 1871 1874 1875 1876 1877 1878 1881 1882 1887 1889 1890 1891 1892 1894 1895 1896 1897 1898 1899 1900 1901 1902 1904 1910 1911 1912 1913 1914 1917 1918 1919 1920 1922 1923 1924 1925 1927 1930 1931 1932 1933 1934 1935 1937 1938 1939 1940 1941 1942 1944 1949 1950 1951 1952 1953 1956 1959 1961 1962 1963 1967 1969 1972 1973 1974 1975 1976 1977 1978 1980 1981 1982 1983 1984 1985 1986 1987 1988 1989 1990 1991 1992 1993 1994 1995 1996 1997 1998 1999 2000 2001 2002 2003 2004 2005 2006 2007 2008 2009 2011 2012 2013 2014 2015 2016 2017 2018 2019 2026 2028 2032 2033 2034 2035 2036 2037 2038 2039 2044 2045 2051 2058 2059 2123 2130 2189 2191 2200 2201 2205 2208 2210 2233 2242 2246 2252 2260 2262 2263 2264 2265 2266 2267 2268 2276 2282 2283 2287 2297 2298 2299 2300 2302 2307 2309 2310 2311 2312 2313 2314 2315 2317 2318 2319 2320 2321 2322 2323 2324 2325 2326 2327 2328 2329 2330 2331 2332 2333 2334 2335 2337 2338 2471 2473 2474 2475 2476 2477 2478 2479 2480 2481 2482 2484 2485 2486 2495 2497 2498 2499 2500 2501 2502 2504 2505 2506 2508 2509 2514 2515 2526 2538 2542 2544 2545 2546 2547 2548 2549 2550 2551 2553 2554 2555 2590`;
const finishedProblemList = new Set(finishedProblemStr.split(' '));

// 获取父级文件夹列表
const directories = fs.readdirSync(root).filter(name => (/\d{4}-\d{4}/).test(name));

// 遍历所有本地写完的题目
const nativeProblemList = new Set();

for (let dir of directories) {
    let files = fs.readdirSync(root + '/' + dir);
    files = files.filter(name => (/.c$/.test(name))).map(name => name.replace(/(\d{4})\S+/, '$1'));
    for (let file of files) {
        nativeProblemList.add(file);
    }
}

// 输出本地写完，但没提交到oj上的题目
console.log('未提交的题目如下：');
for (let file of nativeProblemList) {
    if (!finishedProblemList.has(file)) {
        console.log(Number.parseInt(file));
    }
}