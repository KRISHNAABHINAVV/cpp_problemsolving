/*Array.prototype.last*/
Array.prototype.last = function() {
    return this.length === 0 ? -1 : this[this.length - 1];
};
let nums1 = [null, {}, 3];
console.log(nums1.last());  // Output: 3

let nums2 = [];
console.log(nums2.last());  // Output: -1
