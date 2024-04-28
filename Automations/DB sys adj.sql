-- task file rename
UPDATE problems SET description_filename=CONCAT(name, ") ", full_name, ".pdf") WHERE name RLIKE '[0-9]{3}';

-- No test allowed
UPDATE problems SET test_allowed=0 WHERE test_allowed=1;