FROM mcr.microsoft.com/dotnet/sdk

WORKDIR /app
COPY main.cs .

RUN dotnet build

ENTRYPOINT ["dotnet", "out/luck.dll"]

