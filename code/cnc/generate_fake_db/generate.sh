#!/bin/sh

# poetry install

poetry run fake2db --rows 20 --db sqlite --name cNEykxUOn --custom name date country email user_name password
mv cNEykxUOn.db ../server/code/files/cNEykxUOn/

poetry run fake2db --rows 20 --db sqlite --name 4LOAAaCW0 --custom email user_name password
mv 4LOAAaCW0.db ../server/code/files/4LOAAaCW0/
