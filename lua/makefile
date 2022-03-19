build:
	@echo "Buildimg luck docker image..."
	@docker build -t luck . 
	@docker run luck
	@echo "Cleaning environment..."
	@docker rm $$(docker ps -a -q --filter ancestor=luck) > /dev/null
	@echo "Done!"
