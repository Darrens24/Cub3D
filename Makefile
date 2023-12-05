all: 
	@make -C ./cub3D

clean:
	@make clean -C ./cub3D
	@make clean -C ./cub3D_bonus

fclean:
	@make fclean -C ./cub3D
	@make fclean -C ./cub3D_bonus

bonus:
	@make -C ./cub3D_bonus

re: fclean all

.PHONY: all clean fclean re bonus
