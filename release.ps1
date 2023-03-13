# Use this Powershell script to push releases
$version = "v0.1.0" 
$commit  = "initial release" 
git add . && git commit -m "$commit" && git push origin && gh release create $version --title "$version" --notes "$commit"