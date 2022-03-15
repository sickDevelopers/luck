build:
	@echo "Buildimg luck-js docker image..."
	@docker build -t luck-js . > /dev/null
	@docker run luck-js
	@echo "Cleaning environment..."
	@docker rm $$(docker ps -a -q --filter ancestor=luck-js) > /dev/null
	@echo "Done!"	
