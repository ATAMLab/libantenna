# Use this Powershell script to push releases
$version = "v0.2.0" 
$commit  = "libconst dependency" 
git add . && git commit -m "$commit" && git push origin && gh release create $version --title "$version" --notes "$commit"