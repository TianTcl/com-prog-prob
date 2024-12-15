-- task file rename
UPDATE problems SET description_filename=CONCAT(name, ") ", full_name, ".pdf") WHERE description_filename=CONCAT(name, ".pdf") AND name RLIKE '[0-9]{3}';
UPDATE problems SET description_filename=CONCAT(name, ") ", full_name, ".pdf") WHERE description_filename=CONCAT(name, ".pdf") AND name RLIKE 'B[0-9]{3}';

-- No test allowed
UPDATE problems SET test_allowed=0 WHERE test_allowed=1;

-- Edit PDF filenames at web/data/tasks/*

-- sh cafe_grader/judge/scripts/clear-space.sh