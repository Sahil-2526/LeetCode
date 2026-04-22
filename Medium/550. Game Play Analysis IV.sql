WITH comp AS (
    SELECT 
        player_id,
        event_date,
        ROW_NUMBER() OVER (
            PARTITION BY player_id 
            ORDER BY event_date
        ) AS rn
    FROM Activity
)

SELECT 
    ROUND(
        COUNT(DISTINCT c1.player_id) / 
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM comp c1
JOIN comp c2
  ON c1.player_id = c2.player_id
WHERE c1.rn = 1 
  AND c2.rn = 2
  AND DATEDIFF(c2.event_date, c1.event_date) = 1;