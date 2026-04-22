SELECT DISTINCT num AS ConsecutiveNums
FROM (
  SELECT 
    num,
    id,
    LAG(id, 1) OVER (PARTITION BY num ORDER BY id) AS id2,
    LAG(id, 2) OVER (PARTITION BY num ORDER BY id) AS id3
  FROM Logs
) t
WHERE id = id2 + 1 
  AND id2 = id3 + 1;